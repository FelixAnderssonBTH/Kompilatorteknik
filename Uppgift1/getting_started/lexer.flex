%top{
    #include "parser.tab.hh"
    #define YY_DECL yy::parser::symbol_type yylex()
    #include "Node.h"
    int lexical_errors = 0;
}
%option yylineno noyywrap nounput batch noinput stack 
%%
"+"                     {if(USE_LEX_ONLY) {printf("PLUSOP ");} else {return yy::parser::make_PLUSOP(yytext);}}
"-"                     {if(USE_LEX_ONLY) {printf("SUBOP ");} else {return yy::parser::make_MINUSOP(yytext);}}
"*"                     {if(USE_LEX_ONLY) {printf("MULTOP ");} else {return yy::parser::make_MULTOP(yytext);}}
"("                     {if(USE_LEX_ONLY) {printf("LP ");} else {return yy::parser::make_LP(yytext);}}
")"                     {if(USE_LEX_ONLY) {printf("RP ");} else {return yy::parser::make_RP(yytext);}}
"{"                     {if(USE_LEX_ONLY) {printf("LB ");} else {return yy::parser::make_LB(yytext);}}
"}"                     {if(USE_LEX_ONLY) {printf("RB ");} else {return yy::parser::make_RB(yytext);}}
"["                     {if(USE_LEX_ONLY) {printf("LS ");} else {return yy::parser::make_LS(yytext);}}
"]"                     {if(USE_LEX_ONLY) {printf("RS ");} else {return yy::parser::make_RS(yytext);}}
";"                     {if(USE_LEX_ONLY) {printf("SEMI ");} else {return yy::parser::make_SEMI(yytext);}}
"<"                     {if(USE_LEX_ONLY) {printf("LEFT_ARROW ");} else {return yy::parser::make_LEFT_ARROW(yytext);}}
">"                     {if(USE_LEX_ONLY) {printf("RIGHT_ARROW ");} else {return yy::parser::make_RIGHT_ARROW(yytext);}}
"&&"                    {if(USE_LEX_ONLY) {printf("AND ");} else {return yy::parser::make_AND(yytext);}}
"||"                    {if(USE_LEX_ONLY) {printf("OR ");} else {return yy::parser::make_OR(yytext);}}
"=="                    {if(USE_LEX_ONLY) {printf("EQUAL ");} else {return yy::parser::make_EQUAL(yytext);}}
"/"                     {if(USE_LEX_ONLY) {printf("DIVIDE ");} else {return yy::parser::make_DIVIDE(yytext);}}
"!"                     {if(USE_LEX_ONLY) {printf("NOT ");} else {return yy::parser::make_NOT(yytext);}}
"."                     {if(USE_LEX_ONLY) {printf("DOT ");} else {return yy::parser::make_DOT(yytext);}}
"="                     {if(USE_LEX_ONLY) {printf("EUQUAL_SIGN ");} else {return yy::parser::make_EUQUAL_SIGN(yytext);}}
","                     {if(USE_LEX_ONLY) {printf("COM ");} else {return yy::parser::make_COM(yytext);}}
"class"                 {if(USE_LEX_ONLY) {printf("CLASS ");} else {return yy::parser::make_CLASS(yytext);}}
"public"                {if(USE_LEX_ONLY) {printf("PUBLIC ");} else {return yy::parser::make_PUBLIC(yytext);}}
"void"                  {if(USE_LEX_ONLY) {printf("VOID ");} else {return yy::parser::make_VOID(yytext);}}
"static"                {if(USE_LEX_ONLY) {printf("STATIC ");} else {return yy::parser::make_STATIC(yytext);}}
"main"                  {if(USE_LEX_ONLY) {printf("MAIN ");} else {return yy::parser::make_MAIN(yytext);}}
"String"                {if(USE_LEX_ONLY) {printf("STRING ");} else {return yy::parser::make_STRING(yytext);}}
"boolean"               {if(USE_LEX_ONLY) {printf("BOOL ");} else {return yy::parser::make_BOOL(yytext);}}
"int"                   {if(USE_LEX_ONLY) {printf("INTEGER ");} else {return yy::parser::make_INTEGER(yytext);}}
"if"                    {if(USE_LEX_ONLY) {printf("IF ");} else {return yy::parser::make_IF(yytext);}}
"else"                  {if(USE_LEX_ONLY) {printf("ELSE ");} else {return yy::parser::make_ELSE(yytext);}}
"while"                 {if(USE_LEX_ONLY) {printf("WHILE ");} else {return yy::parser::make_WHILE(yytext);}}
"true"                  {if(USE_LEX_ONLY) {printf("TRUE ");} else {return yy::parser::make_TRUE(yytext);}}
"false"                 {if(USE_LEX_ONLY) {printf("FALSE ");} else {return yy::parser::make_FALSE(yytext);}}
"this"                  {if(USE_LEX_ONLY) {printf("THIS ");} else {return yy::parser::make_THIS(yytext);}}
"new"                   {if(USE_LEX_ONLY) {printf("NEW ");} else {return yy::parser::make_NEW(yytext);}}
"return"                {if(USE_LEX_ONLY) {printf("RETURN ");} else {return yy::parser::make_RETURN(yytext);}}
"lenght"                {if(USE_LEX_ONLY) {printf("LENGHT ");} else {return yy::parser::make_LENGHT(yytext);}}
"System.out.println"    {if(USE_LEX_ONLY) {printf("PRINT ");} else {return yy::parser::make_PRINT(yytext);}}

0|[1-9][0-9]*           {if(USE_LEX_ONLY) {printf("INT ");} else {return yy::parser::make_INT(yytext);}}
[a-zA-Z][a-zA-Z0-9_]*   {if(USE_LEX_ONLY) {printf("STR ");} else {return yy::parser::make_STR(yytext);}}

[ \t\n\r]+              {}
"//"[^\n]*              {}
.                       { if(!lexical_errors) fprintf(stderr, "Lexical errors found! See the logs below: \n"); fprintf(stderr,"\t@error at line %d. Character %s is not recognized\n", yylineno, yytext); lexical_errors = 1;}
<<EOF>>                  {return yy::parser::make_END();}
%%