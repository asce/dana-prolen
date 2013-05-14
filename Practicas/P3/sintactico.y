%{

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "lex.yy.c"

void yyerror(char *msg) ;



%}
%error-verbose

%token MAIN
%token INICIO 
%token FINBLO 
%token INICIOV
%token FINV 
%token PYC
%token COMA
%token TIPOSIMPLE
%token PROCED
%token CORIZ
%token CORDER
%token IF
%token ELSE
%token WHILE 
%token READ 
%token WRITE
%token SWITCH
%token CASE
%token DEFAULT
%token DOSP
%token BREAK
%token CONSTANTE
%token PARDER
%token PARIZ
%token CADENA
%token IDENTIFICADOR 
%token CONSTANTE_E 
%token CARACTER


%right ASIG
%right OPU

%left OPB_ARRAY_MUL  /* ** */
%left OPB_OR         /* || */
%left OPB_AND        /* && */
%left OPB_IG         /* ==, !=  */
%left OPB_REL        /* <, >, <=, >=  */
%left OPB_ADD        /* +,- */
%left OPB_MUL        /* *, /, %  */

%start programa

%%
programa: cabecera_programa bloque {printf("\nAnalisis sintactico finalizado.\n"); return 0;};

cabecera_programa: MAIN;

bloque : inicio_de_bloque declar_de_variables_locales declar_de_subprogs sentencias fin_de_bloque;

inicio_de_bloque:INICIO;

fin_de_bloque:FINBLO;

declar_de_subprogs: declar_de_subprogs declar_subprog | ;

declar_subprog: cabecera_subprograma bloque;

cabecera_subprograma: PROCED IDENTIFICADOR PARIZ declar_parametros PARDER
|PROCED IDENTIFICADOR PARIZ PARDER;

declar_parametros: declar_parametros COMA TIPOSIMPLE iden | TIPOSIMPLE iden | error;//error3

//mas_parametros: mas_parametros TIPOSIMPLE iden COMA |;
//Ojo



iden: IDENTIFICADOR | IDENTIFICADOR CORIZ expresion CORDER | IDENTIFICADOR CORIZ expresion COMA expresion CORDER;//| error;

declar_de_variables_locales: INICIOV TIPOSIMPLE linea FINV | ;

linea: elems TIPOSIMPLE elems | elems;

elems: iden COMA elems | iden PYC | error;

//variables_locales:  variables_locales TIPOSIMPLE lista_variables PYC | TIPOSIMPLE lista_variables PYC | error ;//sincroniza con tipo;


//cuerpo_declar_variables: TIPOSIMPLE iden lista_elem_variable ;
//elem_variable: COMA iden ;
//lista_elem_variable: elem_variable lista_elem_variable | PYC | error ;

//cuerpo_declar_variables: lista_variables  | error;
lista_variables: lista_variables COMA iden | iden ;//| error ;//sincroniza con PYC

sentencias: sentencias sentencia | sentencia;

sentencia: bloque
           |sentencia_asignacion
	   | sentencia_if
           | sentencia_while
	   | sentencia_entrada
	   | sentencia_salida
	   | procedimiento
           | sentencia_case | error;

sentencia_asignacion: iden ASIG expresion PYC;

expresion: PARIZ expresion PARDER
		| OPU expresion
		| expresion OPB_IG expresion
		| expresion OPB_REL expresion
		| expresion OPB_ADD expresion
		| expresion OPB_MUL expresion
		| expresion OPB_OR expresion
		| expresion OPB_AND expresion
		| expresion OPB_ARRAY_MUL expresion
		| iden
		| CONSTANTE 
		| CONSTANTE_E
		| CARACTER
		| CADENA
		| procedimiento
                | agregados;
                | error;

procedimiento: IDENTIFICADOR PARIZ lista_expresiones PARDER;

agregados: INICIO lista_expresiones FINBLO;

lista_expresiones: lista_expresiones COMA expresion | expresion;

sentencia_if: alternativa_doble	| alternativa_simple;
//2
alternativa_simple: IF expresion sentencia;

alternativa_doble: IF expresion sentencia ELSE sentencia;

sentencia_while: WHILE PARIZ expresion PARDER sentencia;

sentencia_entrada: READ lista_variables PYC;

sentencia_salida: WRITE PARIZ lista_expresiones PARDER PYC;

sentencia_case: SWITCH PARIZ IDENTIFICADOR PARDER INICIO casos caso_por_defecto FINBLO;

casos: casos CASE opcion DOSP sentencias BREAK PYC | ;

opcion: CONSTANTE_E | CARACTER;

caso_por_defecto: DEFAULT DOSP sentencias | ;


%%
void yyerror( char *msg )
{
	printf("\nLinea %d: ERROR-> %s y se ha encontrado: %s\n", yylineno, msg, yytext);
	

}
