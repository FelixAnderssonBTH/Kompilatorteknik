%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

%code requires{
  #include <string>
  #include "Node.h"
  #define USE_LEX_ONLY false //change this macro to true if you want to isolate the lexer from the parser.
}

%code{
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;
}

// definition of set of tokens. All tokens are of type string
%token <std::string> INT LS RS CEMI NOT DOT EUQUAL_SIGN SEMI CLASS EXTENDS PUBLIC VOID STATIC MAIN STRING BOOL INTEGER IF ELSE WHILE TRUE FALSE THIS NEW RETURN LENGHT PRINT STR ID
%token <std::string> LP RP LB RB
%token <std::string> PLUSOP MINUSOP MULTOP DIVIDE AND OR EQUAL LEFT_ARROW RIGHT_ARROW
%token END 0 "end of file"

// definition of the production rules. All production rules are of type Node
%type <Node *> root VarDeclaration MethodDeclaration MethodDeclaration_Body Recursive_MethodDeclaration Type Statement Recursive_statement Expression factor Identifier

%%
root:       Expression {root = $1;};
 
VarDeclaration: Type Identifier SEMI  {$$ = new Node("VarDeclaration", ""); $$->children.push_back($1); $$->children.push_back($2);};

MethodDeclaration: PUBLIC Type Identifier LP RP LB MethodDeclaration_Body RB
            | PUBLIC Type Identifier LP RP LB RETURN Expression SEMI RB

MethodDeclaration_Body: RETURN Expression SEMI {$$ = $2;}
            | Recursive_MethodDeclaration RETURN Expression SEMI {$$ = new Node("MethodDeclaration_Body", "");$$->children.push_back($1); $$->children.push_back($3);}
            | Recursive_MethodDeclaration Recursive_MethodDeclaration RETURN Expression SEMI {$$ = new Node("MethodDeclaration_Body", "");$$->children.push_back($1); $$->children.push_back($2); $$->children.push_back($4);};

Recursive_MethodDeclaration: VarDeclaration {$$ = new Node("MethodDeclaration_Variables", ""); $$->children.push_back($1);}
            | Recursive_MethodDeclaration VarDeclaration {$$ = $1; $$->children.push_back($2);};
            |Statement {$$ = new Node("MethodDeclaration_Statements", ""); $$->children.push_back($1);}
            | Recursive_MethodDeclaration Statement {$$ = $1; $$->children.push_back($2);};

Type: INTEGER LB RB {$$ = new Node("Type", "int[]");}
            | BOOL {$$ = new Node("Type", "boolean");}
            | INTEGER {$$ = new Node("Type", "integer");}
            | Identifier {$$ = new Node("Type", "Identifier"); $$->children.push_back($1);};

Statement:
LP RP { $$ = new Node("EmptyStatement", "",yylineno); }
            | LP Recursive_statement RP {$$ = $2;}
            | IF LP Expression RP Statement ELSE Statement {$$ = new Node(" IfElseStatement", ""); $$->children.push_back($3); $$->children.push_back($5); $$->children.push_back($7);}
            | WHILE LP Expression RP Statement {$$ = new Node("WhileStatement", ""), $$->children.push_back($3), $$->children.push_back($5);}
            | PRINT LP Expression RP SEMI {$$ = new Node("PrintStatement", ""); $$->children.push_back($3);}
            | Identifier EUQUAL_SIGN Expression SEMI { $$ = new Node("AssinedExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
            | Identifier LS Expression RS EUQUAL_SIGN Expression SEMI { $$ = new Node("AssinedExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);$$->children.push_back($6);}

Recursive_statement: 
  Statement {$$ = $1;}
| Recursive_statement Statement { $$ = new Node("Statement", ""); $$->children.push_back($1); $$->children.push_back($2);};          


Expression:
Expression PLUSOP Expression { $$ = new Node("AddExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3); }
            | Expression MINUSOP Expression { $$ = new Node("SubExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
            | Expression MULTOP Expression { $$ = new Node("MultExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
            | Expression DIVIDE Expression { $$ = new Node("DivideExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
            | Expression AND Expression { $$ = new Node("AndExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
            | Expression OR Expression { $$ = new Node("OrExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
            | Expression EQUAL Expression { $$ = new Node("EqualExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
            | Expression LEFT_ARROW Expression { $$ = new Node("LeftArrowExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
            | Expression RIGHT_ARROW Expression { $$ = new Node("RightArrowExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
            | Expression LS Expression RS { $$ = new Node("ArrayExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
            | Expression DOT Expression LENGHT { $$ = new Node("LenghtExpression", "", yylineno); $$->children.push_back($1);}
            | TRUE {$$ = new Node("TRUE", "",yylineno);}
            | FALSE {$$ = new Node("FALSE", "",yylineno);}
            | THIS {$$ = new Node("THIS", "",yylineno);}
            | NEW INTEGER LS Expression RS {$$ = new Node("newIntExpression", "",yylineno); $$->children.push_back($4);}
            | NEW Identifier LP RP {$$ = new Node("newIdentifierExpression", "",yylineno); $$->children.push_back($2);}
            | NOT Expression {$$ = new Node("NotExpression", "",yylineno); $$->children.push_back($2);}
            | LP Expression RP {$$ = new Node("BracketsExpression", "",yylineno); $$->children.push_back($2);}
            | factor      {$$ = $1; /* printf("r4 ");*/};
            | Identifier      {$$ = $1; /* printf("r4 ");*/};

factor:     INT           {  $$ = new Node("Int", $1, yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
            | LP Expression RP { $$ = $2; /* printf("r6 ");  simply return the expression */};
Identifier: STR           {  $$ = new Node("Str", $1, yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
            | LP Expression RP { $$ = $2; /* printf("r6 ");  simply return the expression */};





