%{

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "lex.yy.c"
#define MAXTS 1000 

void yyerror(const char *msg) ;

typedef enum{
	marca,	/* marca comienzo bloque */
	procedimiento,	/* si es subprograma */
	variable,	/* si es variable */
	parametro_formal,	/* si es parametro formal */
}tipoEntrada;

typedef enum{
	entero,
	real,
	caracter,
	booleano,
	array_1d_int,
	array_1d_real,
	array_1d_char,
	array_1d_bool,
	array_1d_string,
	array_2d_int,
	array_2d_real,
	array_2d_char,
	array_2d_bool,
	array_2d_string,
	desconocido,
	no_asignado,
	string,
	error,
}dtipo;

typedef struct {
	char *lexema ; /* Nombre del lexema */
	dtipo tipo ; /* Tipo del símbolo */
	int atrib;
} atributos ;


typedef struct {
	tipoEntrada entrada ;
	char *nombre ;
	dtipo tipoDato ;
	unsigned int parametros ;
	unsigned int dimensiones;
} entradaTS ;


long int TOPE=0 ; /* Tope de la pila */
unsigned int Subprog;	/* Indicador de comienzo de bloque de un subprog */
entradaTS TS[MAXTS] ; /* Pila de la tabla de símbolos */
#define YYSTYPE atributos

/* A partir de ahora, cada símbolo tiene */ 
/* una estructura de tipo atributos */

/* Lista de funciones y procedimientos para menejo de la TS */

/*
 * Devuelve una cadena que describe un tipo "t"
 */
char * cadenaTipo(int t){
  char *s;
  switch(t){
	case desconocido	: s=strdup("desconocido"); 
      		break;
	case no_asignado	: s=strdup("no_asignado"); 
      		break;
	case error		: s=strdup("error"); 
      		break;
	case entero	        : s=strdup("entero"); 
      		break;
	case real		: s=strdup("real"); 
     		break;
	case caracter		: s=strdup("caracter"); 
      		break;
	case booleano		: s=strdup("booleano"); 
      		break;
	case array_1d_int   	: s=strdup("array_1d_int"); 
      		break;
    	case array_1d_real	: s= strdup("array_1d_real");
		break;
	case array_1d_char	: s= strdup("array_1d_char");
		break;
	case array_1d_bool	: s= strdup("array_1d_bool");
		break;
	case array_1d_string	: s= strdup("array_1d_string");
		break;
	case array_2d_int	: s= strdup("array_2d_int");
		break;
	case array_2d_real	: s= strdup("array_2d_real");
		break;
	case array_2d_char	: s= strdup("array_2d_char");
		break;
	case array_2d_bool	: s= strdup("array_2d_bool");
		break;
	case array_2d_string	: s= strdup("array_2d_string");
		break;
    }
  return s;
}

/*
 * Aniade un identificador a la tabla de simbolos
 */
int nuevoIdentificador(char *s, tipoEntrada tipo_ent,int linea_actual){
	int i, linea_id_anterior;
  
	if((TOPE+1) == MAXTS){
 		printf("\nError PILA LLENA.\n");
 		return 0;	// Error
 	
 	}

	switch (tipo_ent){
		case variable:
	//printf("\nEntra en VARIABLE\n");
			linea_id_anterior = buscaIdBloque(s);
			if( linea_id_anterior != -1 ){
				printf("\nERROR SEMANTICO: Linea %d: Identificador %s declarado anteriormente.\n",linea_actual, s);
				return 0;
			}else{
				TOPE++;
				TS[TOPE].entrada = variable;
//printf("\n TS: nombre -> %s tipo -> %s  \n", TS[TOPE].nombre, cadenaTipo(TS[TOPE].tipoDato) );
			}
			break;
		
		case parametro_formal:
//printf("\nEntra en PARAMETRO FORMAL\n");
			linea_id_anterior = buscaParam(s);
			if( linea_id_anterior != -1 ){
				printf("ERROR SEMANTICO: Linea %d: Parametro %s declarado anteriormente en linea %d.\n",linea_actual,s, linea_id_anterior);
				return 0;
			}else{
				TOPE++;
				TS[TOPE].entrada = parametro_formal;
			}
			break;
	
		case funcion:
//printf("\nEntra en FUNCION\n");
			linea_id_anterior = buscaIdBloque(s);
			if( linea_id_anterior != -1 ){
				printf("ERROR SEMANTICO: Linea %d: Identificador de funcion %s declarado anteriormente.\n", linea_actual, s);
				return 0;
			}else{
				TOPE++;
				TS[TOPE].entrada = funcion;
			}
			break;
	}
	
//printf("\nFIN nuevoIdentificador1\n");
	TS[TOPE].nombre = strdup(s);
	TS[TOPE].tipoDato = no_asignado;

//printf("\n TS: nombre -> %s tipo -> %s  \n", TS[TOPE].nombre, cadenaTipo(TS[TOPE].tipoDato) );
	//TS[TOPE].numLinea = num_linea;
		
//printf("\nFIN nuevoIdentificador3\n");
	return 1;
}





/* Fin de funciones y procedimientos para manejo de la TS */

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
programa: cabecera_programa bloque {printf("\nAnalisis sintactico finalizado.\n"); return 0;};

cabecera_programa: MAIN;

bloque : inicio_de_bloque declar_de_variables_locales declar_de_subprogs sentencias fin_de_bloque;

inicio_de_bloque:INICIO;

fin_de_bloque:FINBLO;

declar_de_subprogs: declar_de_subprogs declar_subprog | ;

declar_subprog: cabecera_subprograma bloque;

cabecera_subprograma: PROCED IDENTIFICADOR PARIZ declar_parametros PARDER
|PROCED IDENTIFICADOR PARIZ PARDER;

declar_parametros: declar_parametros COMA TIPOSIMPLE iden | TIPOSIMPLE iden;


iden: IDENTIFICADOR | IDENTIFICADOR CORIZ expresion CORDER | IDENTIFICADOR CORIZ expresion COMA expresion CORDER;

declar_de_variables_locales: INICIOV variables_locales FINV | ;
variables_locales:variables_locales cuerpo_decla_variables
	|cuerpo_decla_variables;

cuerpo_decla_variables: TIPOSIMPLE lista_variables PYC;

lista_variables: lista_variables COMA iden | iden | error ;//sincroniza con COMA o PYC

sentencias: sentencias sentencia | sentencia;

sentencia: bloque
           |sentencia_asignacion
	   | sentencia_if
           | sentencia_while
	   | sentencia_entrada
	   | sentencia_salida
	   | procedimiento
           | sentencia_case;

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
                | agregados;

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
void yyerror( const char *msg )
{
	printf("\nLinea %d: ERROR-> %s y se ha encontrado: %s\n", yylineno, msg, yytext);
	

}
