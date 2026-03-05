#include "Node.h"
#include "parser.tab.hh"
#include "symbolTable.cc"
#include <iostream>

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

void traverse_ast(Node *root, SymbolTable &st) {}

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
