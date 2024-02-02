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
%token <std::string> INT LS RS COM NOT DOT EUQUAL_SIGN SEMI CLASS PUBLIC VOID STATIC MAIN STRING BOOL INTEGER IF ELSE WHILE TRUE FALSE THIS NEW RETURN LENGHT PRINT STR LP RP LB RB PLUSOP SUBOP MULTOP DIVIDE AND OR EQUAL LEFT_ARROW RIGHT_ARROW
%token END 0 "end of file"

%left EUQUAL_SIGN 
%left OR
%left AND
%left EQUAL 
%left LEFT_ARROW RIGHT_ARROW 
%left PLUSOP SUBOP
%left MULTOP DIVIDE
%left LP RP LB RB
// definition of the production rules. All production rules are of type Node
%type <Node *> Goal Recursive_ClassDeclaration MainClass ClassDeclaration Recursive_ClassDeclarationVar Recursive_ClassDeclarationMeth VarDeclaration MethodDeclaration MethodDeclaration_Body MethodDeclaration_Variables Recursive_MethodDeclaration Type Statement Recursive_statement Expression Recursive_Expression factor Identifier



%%
Goal: MainClass END  {$$ = $1; root = $$;}
            | MainClass Recursive_ClassDeclaration END {$$ = $1; $$->children.push_back($2); root = $$;};

Recursive_ClassDeclaration: ClassDeclaration {$$ = new Node("Recursive_ClassDeclaration", "", yylineno); $$->children.push_back($1);}
            | Recursive_ClassDeclaration ClassDeclaration {$$ = $1; $$->children.push_back($2);};

MainClass:
PUBLIC CLASS Identifier LB PUBLIC STATIC VOID MAIN LP STRING LS RS Identifier RP LB Recursive_statement RB RB {$$ = new Node("Main Class", "", yylineno); $$->children.push_back($3); $$->children.push_back($13); $$->children.push_back($16);};

ClassDeclaration: CLASS Identifier LB RB {$$ = new Node("EmptyClass", "", yylineno);$$->children.push_back($2);}
            | CLASS Identifier LB Recursive_ClassDeclarationVar RB {$$ = new Node("ClassDeclaration", "", yylineno);$$->children.push_back($2);$$->children.push_back($4);}
            | CLASS Identifier LB Recursive_ClassDeclarationMeth RB{$$ = new Node("ClassDeclaration", "", yylineno);$$->children.push_back($2);$$->children.push_back($4);}
            | CLASS Identifier LB Recursive_ClassDeclarationVar Recursive_ClassDeclarationMeth RB{$$ = new Node("ClassDeclaration", "", yylineno);$$->children.push_back($2);$$->children.push_back($4);$$->children.push_back($5);}

Recursive_ClassDeclarationVar: VarDeclaration {$$ = $1;}
            | Recursive_ClassDeclarationVar VarDeclaration { $$ = new Node("VarDeclaration", "", yylineno); $$->children.push_back($1); $$->children.push_back($2);};      

Recursive_ClassDeclarationMeth: MethodDeclaration {$$ = $1;}
            | Recursive_ClassDeclarationMeth MethodDeclaration { $$ = new Node("MethodDeclaration", "", yylineno); $$->children.push_back($1); $$->children.push_back($2);};    

VarDeclaration: Type Identifier SEMI  {$$ = new Node("VarDeclaration", "", yylineno); $$->children.push_back($1); $$->children.push_back($2);};

MethodDeclaration: PUBLIC Type Identifier LP RP LB MethodDeclaration_Body RB
            | PUBLIC Type Identifier LP MethodDeclaration_Variables RP LB MethodDeclaration_Body RB

MethodDeclaration_Body: RETURN Expression SEMI {$$ = $2;}
            | Recursive_MethodDeclaration RETURN Expression SEMI {$$ = new Node("MethodDeclaration_Body", "", yylineno);$$->children.push_back($1); $$->children.push_back($3);}
            | Recursive_MethodDeclaration Recursive_MethodDeclaration RETURN Expression SEMI {$$ = new Node("MethodDeclaration_Body", "", yylineno);$$->children.push_back($1); $$->children.push_back($2); $$->children.push_back($4);};

MethodDeclaration_Variables: Type Identifier {$$ = new Node("MethodDeclaration_Variables", "", yylineno); $$->children.push_back($1);$$->children.push_back($2);}
            | MethodDeclaration_Variables COM Type Identifier {$$ = $1; $$->children.push_back($3);$$->children.push_back($4);};

Recursive_MethodDeclaration: VarDeclaration {$$ = new Node("MethodDeclaration_Variables", "", yylineno); $$->children.push_back($1);}
            | Recursive_MethodDeclaration VarDeclaration {$$ = $1; $$->children.push_back($2);};
            | Statement {$$ = new Node("MethodDeclaration_Statements", "", yylineno); $$->children.push_back($1);}
            | Recursive_MethodDeclaration Statement {$$ = $1; $$->children.push_back($2);};

Type: INTEGER LS RS {$$ = new Node("Type", "int[]", yylineno);}
            | BOOL {$$ = new Node("Type", "boolean", yylineno);}
            | INTEGER {$$ = new Node("Type", "integer", yylineno);}
            | Identifier {$$ = new Node("Type", "Identifier", yylineno); $$->children.push_back($1);};

Statement:
LB RB { $$ = new Node("EmptyStatement", "",yylineno); }
            | LB Recursive_statement RB {$$ = $2;}
            | IF LP Expression RP Statement ELSE Statement {$$ = new Node(" IfElseStatement", "", yylineno); $$->children.push_back($3); $$->children.push_back($5); $$->children.push_back($7);}
            | IF LP Expression RP Statement {$$ = new Node(" IfElseStatement", "", yylineno); $$->children.push_back($3);$$->children.push_back($5);}
            | WHILE LP Expression RP Statement {$$ = new Node("WhileStatement", "", yylineno), $$->children.push_back($3), $$->children.push_back($5);}
            | PRINT LP Expression RP SEMI {$$ = new Node("PrintStatement", "", yylineno); $$->children.push_back($3);}
            | Identifier EUQUAL_SIGN Expression SEMI { $$ = new Node("AssinedExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
            | Identifier LS Expression RS EUQUAL_SIGN Expression SEMI { $$ = new Node("AssinedExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);$$->children.push_back($6);}

Recursive_statement: Statement {$$ = $1;}
            | Recursive_statement Statement { $$ = new Node("Statement", "", yylineno); $$->children.push_back($1); $$->children.push_back($2);};          


Expression:
Expression PLUSOP Expression { $$ = new Node("AddExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3); }
            | Expression SUBOP Expression { $$ = new Node("SubExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
            | Expression MULTOP Expression { $$ = new Node("MultExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
            | Expression DIVIDE Expression { $$ = new Node("DivideExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
            | Expression AND Expression { $$ = new Node("AndExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
            | Expression OR Expression { $$ = new Node("OrExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
            | Expression EQUAL Expression { $$ = new Node("EqualExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
            | Expression LEFT_ARROW Expression { $$ = new Node("LeftArrowExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
            | Expression RIGHT_ARROW Expression { $$ = new Node("RightArrowExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
            | Expression LS Expression RS { $$ = new Node("ArrayExpression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
            | Expression DOT LENGHT { $$ = new Node("LenghtExpression", "", yylineno); $$->children.push_back($1);}
            | Expression DOT Identifier LP Recursive_Expression RP {$$ = new Node("Recursive_Expression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3); $$->children.push_back($5);}
            | Expression DOT Identifier LP RP {$$ = new Node("Recursive_Expression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
            | factor      {$$ = $1; /* printf("r4 ");*/};
            | TRUE {$$ = new Node("TRUE", "",yylineno);}
            | FALSE {$$ = new Node("FALSE", "",yylineno);}
            | THIS {$$ = new Node("THIS", "",yylineno);}
            | NEW INTEGER LS Expression RS {$$ = new Node("newIntExpression", "",yylineno); $$->children.push_back($4);}
            | NEW Identifier LP RP {$$ = new Node("newIdentifierExpression", "",yylineno); $$->children.push_back($2);}
            | NOT Expression {$$ = new Node("NotExpression", "",yylineno); $$->children.push_back($2);}
            | LP Expression RP {$$ = new Node("BracketsExpression", "",yylineno); $$->children.push_back($2);}
            | Identifier {$$ = $1; /* printf("r4 ");*/};
            


Recursive_Expression: Expression {$$ = $1;}
| Recursive_Expression COM Expression { $$ = new Node("Expression", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);};          


factor:     INT           {  $$ = new Node("Int", $1, yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
            | LP Expression RP { $$ = $2; /* printf("r6 ");  simply return the expression */};
Identifier: STR           {  $$ = new Node("Str", $1, yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
            | LP Expression RP { $$ = $2; /* printf("r6 ");  simply return the expression */};
