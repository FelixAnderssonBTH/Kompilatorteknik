#include "Node.h"
#include "TAC_BB.h"
#include "bytecode.cc"
#include "cfg.cc"
#include "parser.tab.hh"
#include "symbolTable.cc"
#include <iostream>
#include <string>

extern Node *root;
extern FILE *yyin;
extern int yylineno;
extern int lexical_errors;
extern yy::parser::symbol_type yylex();

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

void traverse(Node *root, BasicBlock *&entry, CFG &cfg);
void generateBytecode(CFG &cfg);

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
////////Helper////////////////////////
/// a simple falttner
void flattenArgs(Node *node, vector<Node *> &args) {
  if (node->type == "Expression") {
    for (Node *child : node->children)
      flattenArgs(child, args);
  } else {
    args.push_back(node);
  }
}
string get_str_type(Node *it) {

  if (it && it->value == "Identifier" && !it->children.empty()) {
    return it->children.front()->value;
  }
  return it ? it->value : "unknown";
}
// returns a class rec in scope
ClassRecord *find_class_record(SymbolTable &st, const string &name) {
  auto it = st.globalScope->symbols.find(name);
  if (it != st.globalScope->symbols.end())
    return dynamic_cast<ClassRecord *>(it->second);
  return nullptr;
}

//// returns the scope of a class

Scope *getClassScope(SymbolTable &st, const string &className) {
  auto it = st.globalScope->childrenScopes.find("Class_" + className);
  if (it != st.globalScope->childrenScopes.end()) {
    return it->second;
  } else {
    return nullptr;
  }
}
// get the scope of a method in a class
Scope *getMethodScope(SymbolTable &st, const string &className,
                      const string &methodName) {
  Scope *classScope = getClassScope(st, className);
  if (!classScope)
    return nullptr;
  auto it = classScope->childrenScopes.find("Method_" + methodName);
  if (it != classScope->childrenScopes.end()) {
    return it->second;
  } else {
    return nullptr;
  }
}
string getExprType(Node *node, Scope *sc, SymbolTable &st,
                   const string &currentClass) {
  const string &t = node->type;

  if (t == "Int")
    return "integer";
  if (t == "TRUE" || t == "FALSE")
    return "boolean";
  if (t == "THIS")
    return currentClass;

  if (t == "Str") {
    Record *rec = sc->getRecord(node->value, "var");

    if (!rec) {
      total_errors++;
      cerr << "@error at line " << node->lineno
           << ". semantic (Undeclared identifier '" << node->value << "')\n";
      return "unknown";
    }
    VariableRecord *varRec = dynamic_cast<VariableRecord *>(rec);
    if (varRec && declaration_lines.count(varRec) &&
        node->lineno < declaration_lines[varRec]) {
      total_errors++;
      cerr << "@error at line " << node->lineno << ". semantic (Variable '"
           << node->value << "' used before its declaration)\n";
      return "unknown";
    }
    return rec->type;
  }

  if (t == "ArrayExpression") {
    auto it = node->children.begin();
    string arrayType = getExprType(*it++, sc, st, currentClass);
    string indexType = getExprType(*it, sc, st, currentClass);
    if (arrayType != "int[]" && arrayType != "unknown") {
      total_errors++;
      cerr << "@error at line " << node->lineno
           << ". semantic (Array access on non-array type '" << arrayType
           << "')\n";
    }
    if (indexType != "integer" && indexType != "unknown") {
      total_errors++;
      cerr << "@error at line " << node->lineno
           << ". semantic (Array index must be integer, got '" << indexType
           << "')\n";
    }
    return "integer";
  }
  if (t == "BracketsExpression") {
    return getExprType(node->children.front(), sc, st, currentClass);
  }

  if (t == "LenghtExpression") {
    string arrayType =
        getExprType(node->children.front(), sc, st, currentClass);
    if (arrayType != "int[]" && arrayType != "unknown") {
      total_errors++;
      cerr << "@error at line " << node->lineno
           << ". semantic ('.length' requires int[], got '" << arrayType
           << "')\n";
    }
    return "integer";
  }
  if (t == "EqualExpression") {
    auto it = node->children.begin();
    string leftSideType = getExprType(*it++, sc, st, currentClass);
    string rightSideType = getExprType(*it, sc, st, currentClass);
    if (leftSideType != rightSideType && rightSideType != "unknown" &&
        leftSideType != "unknown") {
      total_errors++;
      cerr << "@error at line " << node->lineno
           << ". semantic ('==' type mismatch: '" << leftSideType << "' vs '"
           << rightSideType << "')\n";
    }
    return "boolean";
  }

  if (t == "AddExpression" || t == "SubExpression" || t == "MultExpression" ||
      t == "DivideExpression") {
    auto it = node->children.begin();
    string leftSideType = getExprType(*it++, sc, st, currentClass);
    string rightSideType = getExprType(*it, sc, st, currentClass);
    if (leftSideType != "integer" && leftSideType != "unknown") {
      total_errors++;
      cerr << "@error at line " << node->lineno
           << ". semantic (Arithmetic operator requires integer operands, left "
              "is '"
           << leftSideType << "')\n";
    }
    if (rightSideType != "integer" && rightSideType != "unknown") {
      total_errors++;
      cerr << "@error at line " << node->lineno
           << ". semantic (Arithmetic operator requires integer operands, "
              "right is '"
           << rightSideType << "')\n";
    }
    return "integer";
  }

  if (t == "NotExpression") {
    string inner = getExprType(node->children.front(), sc, st, currentClass);
    if (inner != "boolean" && inner != "unknown") {
      total_errors++;
      cerr << "@error at line " << node->lineno
           << ". semantic (Operator '!' requires boolean, got '" << inner
           << "')\n";
    }
    return "boolean";
  }

  if (t == "AndExpression" || t == "OrExpression") {
    auto it = node->children.begin();
    string leftSideType = getExprType(*it++, sc, st, currentClass);
    string rightSideType = getExprType(*it, sc, st, currentClass);
    if (leftSideType != "boolean" && leftSideType != "unknown") {
      total_errors++;
      cerr
          << "@error at line " << node->lineno
          << ". semantic (Logical operator requires boolean operands, left is '"
          << leftSideType << "')\n";
    }
    if (rightSideType != "boolean" && rightSideType != "unknown") {
      total_errors++;
      cerr << "@error at line " << node->lineno
           << ". semantic (Logical operator requires boolean operands, right "
              "is '"
           << rightSideType << "')\n";
    }
    return "boolean";
  }

  if (t == "LeftArrowExpression" || t == "RightArrowExpression") {
    auto it = node->children.begin();
    string leftSideType = getExprType(*it++, sc, st, currentClass);
    string rightSideType = getExprType(*it, sc, st, currentClass);
    if (leftSideType != "integer" && leftSideType != "unknown") {
      total_errors++;
      cerr << "@error at line " << node->lineno
           << ". semantic (Relational operator requires integer operands, left "
              "is '"
           << leftSideType << "')\n";
    }
    if (rightSideType != "integer" && rightSideType != "unknown") {
      total_errors++;
      cerr << "@error at line " << node->lineno
           << ". semantic (Relational operator requires integer operands, "
              "right is '"
           << rightSideType << "')\n";
    }
    return "boolean";
  }

  if (t == "newIntExpression") {
    if (!node->children.empty()) {
      string indexType =
          getExprType(node->children.front(), sc, st, currentClass);
      if (indexType != "integer" && indexType != "unknown") {
        total_errors++;
        cerr << "@error at line " << node->lineno
             << ". semantic (Array size must be integer, got '" << indexType
             << "')\n";
      }
    }
    return "int[]";
  }

  if (t == "newIdentifierExpression") {
    if (!node->children.empty()) {
      string className = node->children.front()->value;
      if (!find_class_record(st, className)) {
        total_errors++;
        cerr << "@error at line " << node->lineno
             << ". semantic (Undefined class '" << className << "')\n";
        return "unknown";
      }
      return className;
    }
    return "unknown";
  }
  if (t == "Recursive_Expression") {
    auto it = node->children.begin();
    if (node->children.size() < 2)
      return "unknown";

    Node *calleeNode = *it++;
    Node *methodNameNode = *it++;
    string calleeType = getExprType(calleeNode, sc, st, currentClass);
    if (calleeType == "unknown")
      return "unknown";

    Scope *classScope = getClassScope(st, calleeType);
    if (!classScope) {
      total_errors++;
      cerr << "@error at line " << node->lineno << ". semantic (Type '"
           << calleeType << "' is not a class)\n";
      return "unknown";
    }

    string methodName = methodNameNode->value;
    MethodRecord *methRec = nullptr;
    Record *record = classScope->getRecord(methodName, "method");
    if (record)
      methRec = dynamic_cast<MethodRecord *>(record);

    if (!methRec) {
      total_errors++;
      cerr << "@error at line " << node->lineno << ". semantic (Method '"
           << methodName << "' not found in class '" << calleeType << "')\n";
      return "unknown";
    }

    vector<Node *> args;
    for (; it != node->children.end(); ++it)
      flattenArgs(*it, args);
    if (args.size() != methRec->param_list.size()) {
      total_errors++;
      cerr << "@error at line " << node->lineno << ". semantic (Method '"
           << methodName << "' in '" << calleeType << "' expects "
           << methRec->param_list.size() << " argument(s), got " << args.size()
           << ")\n";
    } else {
      for (size_t i = 0; i < args.size(); i++) {
        string argType = getExprType(args[i], sc, st, currentClass);
        string paramType = methRec->param_list[i]->type;
        if (argType != "unknown" && paramType != "unknown" &&
            argType != paramType) {
          total_errors++;
          cerr << "@error at line " << args[i]->lineno
               << ". semantic (Argument " << (i + 1) << " of '" << methodName
               << "' expects '" << paramType << "', got '" << argType << "')\n";
        }
      }
    }

    return methRec->return_type;
  }
  return "unknown";
}
/////////////////////////////////////////
// implement the analysis here
void semantic_analysis(Node *root, SymbolTable &st, Scope &sc,
                       const string &currentClass) {
  const string &start = root->type;

  // if it is a main class
  if (start == "MainClass") {
    string className = root->children.front()->value;
    std::cout << "Main Class FOUND:" + className << std::endl;
    Scope *classScope = getClassScope(st, className);

    // if ther is no scope
    if (!classScope) {
      classScope = st.globalScope;
    }
    Scope *mainMethod = classScope;
    if (classScope->childrenScopes.count("Method_main")) {
      mainMethod = classScope->childrenScopes["Method_main"];
    }

    auto it = root->children.begin();
    advance(it, 2); // skip class name and param name
    for (; it != root->children.end(); ++it)
      semantic_analysis(*it, st, *mainMethod, currentClass);
    return;
  }
  // pass by the recursive class dec
  if (start == "Recursive_ClassDeclarations") {
    for (Node *child : root->children) {
      std::cout << "Recursive_ClassDeclarations found" << std::endl;
      semantic_analysis(child, st, sc, currentClass);
    }
    return;
  }
  // Now we check for normal classes
  if (start == "ClassDeclaration" || start == "EmptyClass") {
    if (!root->children.empty() && root->children.front()->type == "Str") {
      string className = root->children.front()->value;
      std::cout << "Class FOUND:" + className << std::endl;
      Scope *classScope = getClassScope(st, className);
      if (!classScope)
        return;
      for (Node *child : root->children)
        if (child->type != "Str")
          semantic_analysis(child, st, *classScope, className);
    }
    return;
  }
  // pass by  MethodDeclarations
  if (start == "MethodDeclarations") {
    std::cout << "Recursive_MethodDeclarations found" << std::endl;
    for (Node *child : root->children) {
      semantic_analysis(child, st, sc, currentClass);
    }
    return;
  }
  // now method
  if (start == "MethodDeclaration") {

    auto it = root->children.begin();
    string declaredReturnType = get_str_type(*it++);
    Node *methodNameNode = *it;
    std::cout << "Mehod Found: " + methodNameNode->value +
                     " with declared return type " + declaredReturnType
              << std::endl;

    Scope *methodScope =
        getMethodScope(st, currentClass, methodNameNode->value);
    if (!methodScope) {
      methodScope = &sc;
    }
    Node *body = root->children.back();
    if (body->type == "MethodDeclaration_Body") {
      semantic_analysis(body->children.front(), st, *methodScope, currentClass);
      Node *returnExpr = body->children.back();
      string actual = getExprType(returnExpr, methodScope, st, currentClass);
      if (actual != declaredReturnType && actual != "unknown") {
        total_errors++;
        cerr << "@error at line " << returnExpr->lineno
             << ". semantic (Return type mismatch in '" << methodNameNode->value
             << "': expected '" << declaredReturnType << "', got '" << actual
             << "')\n";
      }
    } else {
      // body IS the return expression directly (no pre-statements)
      string actual = getExprType(body, methodScope, st, currentClass);
      if (actual != declaredReturnType && actual != "unknown") {
        total_errors++;
        cerr << "@error at line " << body->lineno
             << ". semantic (Return type mismatch in '" << methodNameNode->value
             << "': expected '" << declaredReturnType << "', got '" << actual
             << "')\n";
      }
    }
  }

  // if the class//method have more than 1 vars pass by this
  if (start == "ClassVarDeclarations" ||
      start == "MethodDeclaration_Variables") {
    std::cout << "Vars found inside class/method" << std::endl;
    for (Node *child : root->children) {
      semantic_analysis(child, st, sc, currentClass);
    }
    return;
  }

  // check a var
  if (start == "VarDeclaration") {
    Node *typeNode = root->children.front();
    Node *nameNode = *std::next(root->children.begin()); // for debug
    std::cout << "Var Found: type: " + typeNode->value +
                     " name: " + nameNode->value
              << std::endl; // for debug
    if (typeNode->value == "Identifier" && !typeNode->children.empty()) {
      string className = typeNode->children.front()->value;
      if (!find_class_record(st, className)) {
        total_errors++;
        cerr << "@error at line " << typeNode->lineno
             << ". semantic (Undefined class type '" << className << "')\n";
      }
    }
    return;
  }

  // now if else
  if (start == " IfElseStatement") {
    std::cout << "if else found" << std::endl;
    auto it = root->children.begin();
    string ct = getExprType(*it++, &sc, st, currentClass);
    if (ct != "boolean" && ct != "unknown") {
      total_errors++;
      cerr << "@error at line " << root->lineno
           << ". semantic (If condition must be boolean, got '" << ct << "')\n";
    }
    for (; it != root->children.end(); ++it)
      semantic_analysis(*it, st, sc, currentClass);
    return;
  }
  // now while
  if (start == "WhileStatement") {
    std::cout << "While found" << std::endl;
    auto it = root->children.begin();
    string ct = getExprType(*it++, &sc, st, currentClass);
    if (ct != "boolean" && ct != "unknown") {
      total_errors++;
      cerr << "@error at line " << root->lineno
           << ". semantic (While condition must be boolean, got '" << ct
           << "')\n";
    }
    semantic_analysis(*it, st, sc, currentClass);
    return;
  }

  if (start == "PrintStatement") {
    std::cout << "PrintStatement found" << std::endl; // just check the children
    getExprType(root->children.front(), &sc, st, currentClass);
    return;
  }
  if (start == "MethodDeclaration_Statements" || start == "Statement") {
    for (Node *child : root->children)
      semantic_analysis(child, st, sc, currentClass);
    return;
  }

  if (start == "EmptyStatement") {
    return;
  }

  if (start == "AssinedExpression") {
    std::cout << "AssinedExpression found" << std::endl;
    auto it = root->children.begin();
    // when we have simple expr like x=1;
    Node *leftSide = *it++;
    string leftSideType = "unknown";
    if (root->children.size() == 2) {
      Node *rightSide = *it;
      Record *rec = sc.getRecord(leftSide->value, "var");
      if (!rec) {
        total_errors++;
        cerr << "@error at line " << leftSide->lineno
             << ". semantic (Undeclared variable '" << leftSide->value
             << "')\n";
      } else {
        VariableRecord *varRec = dynamic_cast<VariableRecord *>(rec);
        if (varRec && declaration_lines.count(varRec) &&
            leftSide->lineno < declaration_lines[varRec]) {
          total_errors++;
          cerr << "@error at line " << leftSide->lineno
               << ". semantic (Variable '" << leftSide->value
               << "' used before its declaration)\n";
        }
        leftSideType = rec->type;
      }
      string rightSideType = getExprType(rightSide, &sc, st, currentClass);
      if (rightSideType != "unknown" && leftSideType != "unknown" &&
          rightSideType != leftSideType) {
        total_errors++;
        cerr << "@error at line " << leftSide->lineno
             << ". semantic (Type mismatch: '" << leftSide->value << "' is '"
             << leftSideType << "', expression is '" << rightSideType << "')\n";
      }
    } else {
      // when we have array x[index]=value;
      Node *index = *it++;
      Node *value = *it;
      Record *rec = sc.getRecord(leftSide->value, "var");
      if (!rec) {
        total_errors++;
        cerr << "@error at line " << leftSide->lineno
             << ". semantic (Undeclared variable '" << leftSide->value
             << "')\n";
      } else if (rec->type != "int[]") {
        total_errors++;
        cerr << "@error at line " << leftSide->lineno << ". semantic ('"
             << leftSide->value << "' is not an array, type is '" << rec->type
             << "')\n";
      }
      string indexType = getExprType(index, &sc, st, currentClass);

      if (indexType != "integer" && indexType != "unknown") {
        total_errors++;
        cerr << "@error at line " << index->lineno
             << ". semantic (Array index must be integer, got '" << indexType
             << "')\n";
      }
      string valueType = getExprType(value, &sc, st, currentClass);
      if (valueType != "integer" && valueType != "unknown") {
        total_errors++;
        cerr << "@error at line " << value->lineno
             << ". semantic (Array element must be integer, got '" << valueType
             << "')\n";
      }
    }
  }
  return;
}

void traverse_ast(Node *root, SymbolTable &st) {
  int depth = 0; // this is to know how many time exit scope shpuld be called
  // -------------------------------------- classes
  // ----------------------------------
  if ((root->type == "MainClass" || root->type == "ClassDeclaration" ||
       root->type == "EmptyClass") &&
      !root->children.empty() && root->children.front()->type == "Str") {
    st.currentScope = st.globalScope;      // since all classes are global
    Node *idNode = root->children.front(); // changed the name to node so that
                                           // i can visualize better

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

    if (st.currentScope->methodSymbols.count(idNode->value)) {

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
    if (st.currentScope->varSymbols.count(idNode->value)) {

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
      currentMethod = st.currentScope->parent->methodSymbols.count(mName)
                          ? st.currentScope->parent->methodSymbols[mName]
                          : nullptr;
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

        if (st.currentScope->varSymbols.count(idNode->value)) {
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
  semantic_analysis(root, st, *st.globalScope, "");

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

        // Assignment 3
        CFG cfg;
        BasicBlock *current = nullptr;
        traverse(root, current, cfg);
        cfg.generate_dot("cfg.dot");
        cout << "\n\n\n";
        for (auto *block : cfg.blocks) {
          block->dump();
        }
        cout << "\n\n\n";
        generateBytecode(cfg);
      } catch (...) {
        errCode = errCodes::AST_ERROR;
      }
    }
  }

  return errCode;
}
