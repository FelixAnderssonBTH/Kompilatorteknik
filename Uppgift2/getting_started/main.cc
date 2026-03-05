#include "Node.h"
#include "helpers.cc"
#include "parser.tab.hh"
#include "symbolTable.cc"
#include <iostream>
#include <string>

extern Node *root;
extern FILE *yyin;
extern int yylineno;
extern int lexical_errors;
extern yy::parser::symbol_type yylex();

///////////////////////////////// this is just so i dont mess up string names
#define CLASSM = "MainClass";
#define CLASSE = "EmptyClass";
#define CLASSD = "ClassDeclaration";
#define VARD = "VarDeclaration";
#define METHD = "MethodDeclaration";
////////////////////////////////
enum errCodes {
  SUCCESS = 0,
  LEXICAL_ERROR = 1,
  SYNTAX_ERROR = 2,
  AST_ERROR = 3,
  SEMANTIC_ERROR = 4,
  SEGMENTATION_FAULT = 139
};

int total_errors = 0;
std::map<Record *, int> declaration_lines; // this is so that we can catch
                                           // variables that are "pre-used"
int errCode = errCodes::SUCCESS;

// Handling Syntax Errors
void yy::parser::error(std::string const &err) {
  if (!lexical_errors) {
    std::cerr << "Syntax errors found! See the logs below:" << std::endl;
    std::cerr << "\t@error at line " << yylineno
              << ". Cannot generate a syntax for this input:" << err.c_str()
              << std::endl;
    std::cerr << "End of syntax errors!" << std::endl;
    errCode = errCodes::SYNTAX_ERROR;
  }
}
// implement the analysis here
void semantic_analysis(Node *root, SymbolTable st) {}

void traverse_ast(Node *root, SymbolTable &st) {
  int depth = 0; // this is to know how many time exit scope shpuld be called
  // -------------------------------------- classes
  // ----------------------------------
  if ((root->type == "MainClass" || root->type == "ClassDeclaration" ||
       root->type == "EmptyClass") &&
      !root->children.empty() && root->children.front()->type == "Str") {
    st.currentScope = st.globalScope; // since all classes are global
    Node *idNode =
        root->children
            .front(); // changed the name to node so that i can visualize better

    // record the class  if it doe not exist
    ClassRecord *classRec = new ClassRecord(idNode->value);
    if (st.currentScope->symbols.count(idNode->value) &&
        dynamic_cast<ClassRecord *>(st.currentScope->symbols[idNode->value])) {
      total_errors++;
      std::cerr << "@error at line " << idNode->lineno
                << ". semantic (Already Declared Class: '" << idNode->value
                << "')\n";
    } else {
      st.addRecord(classRec);
    }

    // now that we have added  the class to the table we enter it
    st.enterScope("Class_" + idNode->value);
    depth++;

    // this is a check for main class
    if (root->type == "MainClass" && root->children.size() > 1) {
      st.enterScope("Method_main");
      depth++;
      auto it = root->children.begin();
      std::advance(it, 1);
      Node *parmNode = *it;
      VariableRecord *parmRec = new VariableRecord(parmNode->value, "String []",
                                                   st.currentScope->name);
      st.addRecord(parmRec);
      declaration_lines[parmRec] = parmNode->lineno;
    }
  }
  // -------------------------------------- methods
  // ----------------------------------
  else if (root->type == "MethodDeclaration" && !root->children.empty() &&
           root->children.front()->type == "Type") {
    auto it = root->children.begin(); // setting iterator so that we can advance
    string retTypeStr = get_str_type(*it++);
    Node *idNode = *it;

    MethodRecord *methRec = new MethodRecord(idNode->value, retTypeStr);

    if (st.currentScope->symbols.count(idNode->value) &&
        dynamic_cast<MethodRecord *>(st.currentScope->symbols[idNode->value])) {

      std::cerr << "@error at line " << idNode->lineno
                << ". semantic (Already Declared Function: '" << idNode->value
                << "')\n";
      total_errors++;

    } else {
      st.addRecord(methRec);
    }
    st.enterScope("Method_" + idNode->value);
    depth++;

  } // --------------------------- Variable ---------------------
  else if (root->type == "VarDeclaration" && !root->children.empty() &&
           root->children.front()->type == "Type") {
    auto it = root->children.begin();
    string varTypeStr = get_str_type(*it++);
    Node *idNode = *it;

    VariableRecord *varRec =
        new VariableRecord(idNode->value, varTypeStr, st.currentScope->name);
    if (st.currentScope->symbols.count(idNode->value) &&
        dynamic_cast<VariableRecord *>(
            st.currentScope->symbols[idNode->value])) {

      bool inMethod = st.currentScope->name.find("Method_") == 0;
      std::cerr << "@error at line " << idNode->lineno
                << ". semantic (Already Declared "
                << (inMethod ? "parameter" : "variable") << ": '"
                << idNode->value << "')\n";
      total_errors++;
    } else {
      st.addRecord(varRec);
      declaration_lines[varRec] = idNode->lineno;
    }
  }
  // --------------method parameters-------
  else if (root->type == "MethodDeclaration_Variables") {

    // Retrieve the parent MethodRecord so we can register parameter order
    MethodRecord *currentMethod = nullptr;
    if (st.currentScope->parent && st.currentScope->name.find("Method_") == 0) {
      string mName = st.currentScope->name.substr(7);
      currentMethod =
          dynamic_cast<MethodRecord *>(st.currentScope->parent->symbols[mName]);
    }

    auto it = root->children.begin();
    while (it != root->children.end()) {
      if ((*it)->type == "Type") {
        string parmType = get_str_type(*it++);
        if (root->children.end() == it) {
          break;
        }
        Node *idNode = *it;

        VariableRecord *parmRec =
            new VariableRecord(idNode->value, parmType, st.currentScope->name);

        if (st.currentScope->symbols.count(idNode->value)) {
          std::cerr << "@error at line " << idNode->lineno
                    << ". semantic (Already Declared parameter: '"
                    << idNode->value << "')\n";
          total_errors++;
          if (currentMethod) {
            currentMethod->param_list.push_back(parmRec);
          }
        } else {
          st.addRecord(parmRec);
          declaration_lines[parmRec] = idNode->lineno;
          if (currentMethod) {
            currentMethod->addParameters(parmRec);
          }
        }
      }
      ++it;
    }
  }
  for (Node *child : root->children) {
    traverse_ast(child, st);
  }
  while (depth-- > 0) {
    st.exitScope();
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// this is where we build the table, note that we do the semantic checks here
void create_symbol_table(Node *root) {
  SymbolTable st;

  if (!root) {
    return;
  } // simple check

  // first we construc the table
  std::cout << "\n--- Constructing Symbol Table ---\n";
  traverse_ast(root, st);

  std::cout << "\n--- Construction complete, printing the table ---\n";
  st.print();

  std::cout << "\n--- Begining semantic analysis ---\n";
  // first we make sure to be in the global scope
  st.currentScope = st.globalScope;
  semantic_analysis(root, st);

  // now print the results
  if (total_errors > 0) {
    errCode = errCodes::SEMANTIC_ERROR;
    std::cout << "\nCompilation failed with " << total_errors
              << " semantic errors.\n";

  } else {
    std::cout << "\nSemantic analysis passed successfully!\n";
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv) {
  // Reads from file if a file name is passed as an argument. Otherwise, reads
  // from stdin.
  if (argc > 1) {
    if (!(yyin = fopen(argv[1], "r"))) {
      perror(argv[1]);
      return 1;
    }
  }
  //
  if (USE_LEX_ONLY)
    yylex();
  else {
    yy::parser parser;

    bool parseSuccess = !parser.parse();

    if (lexical_errors)
      errCode = errCodes::LEXICAL_ERROR;

    if (parseSuccess && !lexical_errors) {
      printf("\nThe compiler successfuly generated a syntax tree for the given "
             "input! \n");

      printf("\nPrint Tree:  \n");
      try {
        root->print_tree();
        root->generate_tree();
        create_symbol_table(root);
      } catch (...) {
        errCode = errCodes::AST_ERROR;
      }
    }
  }

  return errCode;
}
