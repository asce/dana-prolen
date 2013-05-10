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
%token IDENTIFICADOR CONSTANTE_E CARACTER


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

declar_subprog: cabecera_subprograma bloque;

declar_de_variables_locales: marca_ini_declar_variables variables_locales marca_fin_declar_variables | ;

marca_ini_declar_variables: INICIOV;

marca_fin_declar_variables: FINV;

variables_locales: variables_locales cuerpo_declar_variables
			| cuerpo_declar_variables;

cuerpo_declar_variables: TIPOSIMPLE lista_variables PYC;

lista_variables: IDENTIFICADOR
		| lista_variables COMA IDENTIFICADOR
		| IDENTIFICADOR CORIZ dimension_array CORDER
		| lista_variables COMA IDENTIFICADOR CORIZ dimension_array CORDER;


dimension_array: CONSTANTE_E | CONSTANTE_E COMA CONSTANTE_E;

cabecera_subprograma: PROCED IDENTIFICADOR PARIZ declar_parametros PARDER;

declar_parametros: TIPOSIMPLE IDENTIFICADOR 
		| declar_parametros COMA TIPOSIMPLE IDENTIFICADOR;




sentencias: sentencias sentencia
			|sentencia;

sentencia: bloque
		| sentencia_asignacion
		| sentencia_if
		| sentencia_while
		| sentencia_entrada
		| sentencia_salida
		| procedimiento
		| sentencia_case;

sentencia_asignacion: iden_array ASIG expresion PYC;

expresion: PARIZ expresion PARDER
		| OPU expresion
		| expresion OPBIG expresion
		| expresion OPBLOG expresion
		| expresion OPB expresion
		| expresion SUMA_RESTA expresion
		| iden_array
		| CONSTANTE
		| CONSTANTE_E
		| procedimiento
		| agregados;

iden_array: IDENTIFICADOR CORIZ expresion CORDER
		| IDENTIFICADOR CORIZ expresion COMA expresion CORDER;

procedimiento: IDENTIFICADOR PARIZ lista_expresiones PARDER;

agregados: INICIO lista_expresiones FINBLO;

lista_expresiones: expresion
		| lista_expresiones COMA expresion;

sentencia_if: alternativa_doble
		| alternativa_simple;

alternativa_simple: IF expresion sentencia;

alternativa_doble: IF expresion sentencia ELSE sentencia;

sentencia_while: WHILE PARIZ expresion PARDER sentencia;

sentencia_entrada: nomb_entrada lista_variables;

nomb_entrada: READ;

sentencia_salida: nomb_salida PARIZ lista_expresiones_o_cadena PARDER;

nomb_salida: WRITE;

expresion_o_cadena : expresion
		| CADENA;

lista_expresiones_o_cadena: expresion_o_cadena
		| lista_expresiones_o_cadena COMA expresion_o_cadena;

sentencia_case: SWITCH PARIZ IDENTIFICADOR PARDER INICIO caso caso_por_defecto FINBLO;

caso: CASE opcion DOSP sentencia BREAK PYC caso
		| ;

opcion: CONSTANTE_E
		| CARACTER;

caso_por_defecto: DEFAULT DOSP sentencia PYC
		| ;




%%


{
	printf("\nLinea %d: ERROR-> %s y se ha encontrado: %s\n", yylineno, msg, yytext);
	

}

int main(int argc, char **argv)
{
	yyparse();
}