%{

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "lex.yy.c"

void yyerror(char *msg) ;



%}
%error-verbose

%token MAIN 