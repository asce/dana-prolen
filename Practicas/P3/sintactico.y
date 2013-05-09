%{

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "lex.yy.c"

void yyerror(char *msg) ;



%}
%error-verbose

%token MAIN INICIO FINBLO INICIOV FINV PYC COMA TIPOSIMPLE PROCED CORIZ CORDER IF ELSE
%token WHILE READ WRITE SWITCH CASE DEFAULT DOSP BREAK CONSTANTE PARDER PARIZ CADENA
%token IDENTIFICADOR CONSTANTE_E

%right ASIG
%right OPU
%left OPBLOG
%left OPBIG
%left OPB
%left SUMA_RESTA

%start programa

%%
programa: cabecera_programa bloque {printf("\nAnalisis sintactico correcto\n"); return 0;};

cabecera_programa: MAIN;

bloque : inicio_de_bloque declar_de_variables_locales declar_de_subprogs sentencias fin_de_bloque;

inicio_de_bloque:CORIZ;

fin_de_bloque:CORDER;

declar_de_subprogs: declar_de_subprogs declar_subprog | ;

declar_subprog: cabecera_subprog bloque;

declar_de_variables_locales: marca_ini_declar_variables variables_locales marca_fin_declar_variables | ;

marca_ini_declar_variables: INICIOV;

marca_fin_declar_variables: FINV;

variables_locales: variables_locales cuerpo_declar_variables
			| cuerpo_declar_variables;

cuerpo_declar_variables: tipo_de_dato lista_variables;

lista_variables: IDENTIFICADOR | lista_variables COMA IDENTIFICADOR | error;

tipo_de_dato: TIPOSIMPLE | tipo_estructurado;

tipo_estructurado: tipo_array;

tipo_array: TIPOSIMPLE IDENTIFICADOR PARIZ dimension_array PARDER PYC;

dimension_array: constante_entera | constante_entera COMA constante_entera;









%%


{
	printf("\nLinea %d: ERROR-> %s y se ha encontrado: %s\n", yylineno, msg, yytext);
	

}

int main(int argc, char **argv)
{
	yyparse();
}