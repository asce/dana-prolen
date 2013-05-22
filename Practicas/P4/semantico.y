%{

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "tablaSimbolos.h"


void yyerror(const char *msg) ;



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

%token ASIG

%left OPB_OR         /* || */
%left OPB_AND        /* && */
%left OPB_IG         /* ==, !=  */
%left OPB_REL        /* <, >, <=, >=  */
%left OPB_ADD        /* +,- */
%left OPB_MUL        /* **, *, /, %  */
%right OPU

%start programa

%%
programa: {initTS();} cabecera_programa bloque {printf("\nAnalisis sintactico finalizado.\n"); return 0;};

cabecera_programa: MAIN;

bloque : INICIO {IntroIniBloq();} 
declar_de_variables_locales 
{printf("-------------------------------------- NUEVO BLOQUE --------------------------------------\n");
showTS();
getchar();} 
declar_de_subprogs 
sentencias 
FINBLO {IntroFinBloq();}
;


declar_de_subprogs: declar_de_subprogs declar_subprog | ;

declar_subprog: cabecera_subprograma { subProg = 1; } 
bloque { subProg = 0; }
                ;

cabecera_subprograma: PROCED IDENTIFICADOR PARIZ {TS_InsertaSUBPROG(&$2);} declar_parametros PARDER
|PROCED IDENTIFICADOR PARIZ {TS_InsertaSUBPROG(&$2);} PARDER;

declar_parametros: declar_parametros COMA TIPOSIMPLE {tipoTmp = $3.tipo; dec_param_flag = 1;} iden {TS_InsertaPARAMF(&att_tmp);} 
| TIPOSIMPLE {tipoTmp = $1.tipo; dec_param_flag = 1; } iden {TS_InsertaPARAMF(&att_tmp);}
| error;//error3


iden: IDENTIFICADOR 
{ if(dec_param_flag==1){ 
    dec_param_flag = 0; 
    atributocpy(&att_tmp,&$1); 
  } 
}

| IDENTIFICADOR CORIZ expresion CORDER 
{ if(dec_param_flag==1){ 
    dec_param_flag = 0; 
    atributocpy(&att_tmp,&$1); 
    att_tmp.dimensiones = 1; 
    att_tmp.TamDimen1 = 10; /* revisar */ 
  } 
} 

| IDENTIFICADOR CORIZ expresion COMA expresion CORDER 
{ if(dec_param_flag==1){ 
    dec_param_flag = 0; 
    atributocpy(&att_tmp,&$1); 
    att_tmp.dimensiones = 2; 
    att_tmp.TamDimen1 = 10; /* revisar */
    att_tmp.TamDimen2 = 10; /* revisar */
  } 
}
;

declar_de_variables_locales: INICIOV variables_locales FINV | ;
variables_locales:variables_locales cuerpo_decla_variables
	|cuerpo_decla_variables | error;

cuerpo_decla_variables: TIPOSIMPLE {tipoTmp = $1.tipo;} lista_variables PYC;

lista_variables: lista_variables COMA iden | iden | error ;//sincroniza con COMA o PYC

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
		| OPB_ADD expresion %prec OPU
		| expresion OPB_OR expresion
		| expresion OPB_AND expresion
		| expresion OPB_IG expresion
		| expresion OPB_REL expresion
		| expresion OPB_ADD expresion
		| expresion OPB_MUL expresion
		| OPU expresion
		| iden
		| CONSTANTE 
		| CONSTANTE_E
		| CARACTER
                | agregados
                | error;

procedimiento: IDENTIFICADOR PARIZ lista_expresiones PARDER;

agregados: INICIO lista_expresiones FINBLO;

lista_expresiones: lista_expresiones COMA expresion | expresion;

sentencia_if: alternativa_doble	| alternativa_simple;

alternativa_simple: IF expresion sentencia;

alternativa_doble: IF expresion sentencia ELSE sentencia;

sentencia_while: WHILE PARIZ expresion PARDER sentencia;

sentencia_entrada: READ lista_variables PYC;

sentencia_salida: WRITE lista_expresiones_o_cadena PYC;

lista_expresiones_o_cadena: lista_expresiones_o_cadena COMA expresion_o_cadena | expresion_o_cadena;

expresion_o_cadena: expresion | CADENA ;

sentencia_case: SWITCH PARIZ IDENTIFICADOR PARDER INICIO casos caso_por_defecto FINBLO;

casos: casos CASE opcion DOSP sentencias BREAK PYC | ;

opcion: CONSTANTE_E | CARACTER;

caso_por_defecto: DEFAULT DOSP sentencias | ;


%%

#include "lex.yy.c"


void yyerror( const char *msg )
{
	printf("\nLinea %d: ERROR-> %s\n", yylineno, msg);
	

}
