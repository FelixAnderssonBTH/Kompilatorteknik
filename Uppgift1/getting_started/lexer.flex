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
"{"                     {if(USE_LEX_ONLY) {printf("LB ");} else {return yy::parser::make_RP(yytext);}}
"}"                     {if(USE_LEX_ONLY) {printf("RB ");} else {return yy::parser::make_RP(yytext);}}
"["                     {if(USE_LEX_ONLY) {printf("LS ");} else {return yy::parser::make_RP(yytext);}}
"]"                     {if(USE_LEX_ONLY) {printf("RS ");} else {return yy::parser::make_RP(yytext);}}
";"                     {if(USE_LEX_ONLY) {printf("CEMI ");} else {return yy::parser::make_RP(yytext);}}
"<"                     {if(USE_LEX_ONLY) {printf("LEFT_ARROW ");} else {return yy::parser::make_RP(yytext);}}
">"                     {if(USE_LEX_ONLY) {printf("RIGHT_ARROW ");} else {return yy::parser::make_RP(yytext);}}
"&&"                    {if(USE_LEX_ONLY) {printf("AND ");} else {return yy::parser::make_RP(yytext);}}
"||"                    {if(USE_LEX_ONLY) {printf("OR ");} else {return yy::parser::make_RP(yytext);}}
"=="                    {if(USE_LEX_ONLY) {printf("EQUAL ");} else {return yy::parser::make_RP(yytext);}}
"/"                     {if(USE_LEX_ONLY) {printf("DIVIDE ");} else {return yy::parser::make_RP(yytext);}}
"!"                     {if(USE_LEX_ONLY) {printf("NOT ");} else {return yy::parser::make_RP(yytext);}}
"."                     {if(USE_LEX_ONLY) {printf("DOT ");} else {return yy::parser::make_RP(yytext);}}
"="                     {if(USE_LEX_ONLY) {printf("EUQUAL_SIGN ");} else {return yy::parser::make_RP(yytext);}}
","                     {if(USE_LEX_ONLY) {printf("SEMI ");} else {return yy::parser::make_RP(yytext);}}
"class"                 {if(USE_LEX_ONLY) {printf("CLASS ");} else {return yy::parser::make_RP(yytext);}}
"extends"               {if(USE_LEX_ONLY) {printf("EXTENDS ");} else {return yy::parser::make_RP(yytext);}}
"public"                {if(USE_LEX_ONLY) {printf("PUBLIC ");} else {return yy::parser::make_RP(yytext);}}
"void"                  {if(USE_LEX_ONLY) {printf("VOID ");} else {return yy::parser::make_RP(yytext);}}
"static"                {if(USE_LEX_ONLY) {printf("STATIC ");} else {return yy::parser::make_RP(yytext);}}
"main"                  {if(USE_LEX_ONLY) {printf("MAIN ");} else {return yy::parser::make_RP(yytext);}}
"string"                {if(USE_LEX_ONLY) {printf("STRING ");} else {return yy::parser::make_RP(yytext);}}
"boolean"               {if(USE_LEX_ONLY) {printf("BOOL ");} else {return yy::parser::make_RP(yytext);}}
"int"                   {if(USE_LEX_ONLY) {printf("INTEGER ");} else {return yy::parser::make_RP(yytext);}}
"if"                    {if(USE_LEX_ONLY) {printf("IF ");} else {return yy::parser::make_RP(yytext);}}
"else"                  {if(USE_LEX_ONLY) {printf("ELSE ");} else {return yy::parser::make_RP(yytext);}}
"while"                 {if(USE_LEX_ONLY) {printf("WHILE ");} else {return yy::parser::make_RP(yytext);}}
"true"                  {if(USE_LEX_ONLY) {printf("TRUE ");} else {return yy::parser::make_RP(yytext);}}
"false"                 {if(USE_LEX_ONLY) {printf("FALSE ");} else {return yy::parser::make_RP(yytext);}}
"this"                  {if(USE_LEX_ONLY) {printf("THIS ");} else {return yy::parser::make_RP(yytext);}}
"new"                   {if(USE_LEX_ONLY) {printf("NEW ");} else {return yy::parser::make_RP(yytext);}}
"return"                {if(USE_LEX_ONLY) {printf("RETURN ");} else {return yy::parser::make_RP(yytext);}}
"lenght"                {if(USE_LEX_ONLY) {printf("LENGHT ");} else {return yy::parser::make_RP(yytext);}}
"System.out.println"    {if(USE_LEX_ONLY) {printf("PRINTLN ");} else {return yy::parser::make_RP(yytext);}}

0|[1-9][0-9]*           {if(USE_LEX_ONLY) {printf("INT ");} else {return yy::parser::make_INT(yytext);}}
[a-zA-Z][a-zA-Z0-9_]*   {if(USE_LEX_ONLY) {printf("STR ");} else {return yy::parser::make_RP(yytext);}}
[ \t\n\r]+              {}
"//"[^\n]*              {}
.                       { if(!lexical_errors) fprintf(stderr, "Lexical errors found! See the logs below: \n"); fprintf(stderr,"\t@error at line %d. Character %s is not recognized\n", yylineno, yytext); lexical_errors = 1;}
<<EOF>>                  {return yy::parser::make_END();}
%%