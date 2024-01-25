%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

%code requires{
  #include <string>
  #include "Node.h"
  #define USE_LEX_ONLY true //change this macro to true if you want to isolate the lexer from the parser.
}

%code{
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;
}

// definition of set of tokens. All tokens are of type string
%token <std::string> PLUSOP MINUSOP MULTOP INT LP RP LB RB LS RS CEMI LEFT_ARROW RIGHT_ARROW AND OR EQUAL DIVIDE NOT DOT EUQUAL_SIGN SEMI CLASS EXTENDS PUBLIC VOID STATIC MAIN STRING BOOL INTEGER IF ELSE WHILE TRUE FALSE THIS NEW RETURN LENGHT PRINTLN STR
%token END 0 "end of file"

// definition of the production rules. All production rules are of type Node
%type <Node *> Goal MainClass ClassDeclaration VarDeclaration MethodDeclaration Type Statement Expression Identifier

%%
Goal:

MainClass:

ClassDeclaration:

VarDeclaration:

MethodDeclaration:

Type:

Statement:

Expression:

Identifier:



