#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum {
	marca, 						/* marca comienzo bloque */
	procedimiento, 				/* si es subprograma */
	variable, 					/* si es variable */
	parametro, 					/* si es parametro formal */
} tipoEntrada ;

typedef enum {
	entero,
	real,
	caracter,
	booleano,
	array_entero,
	array_real,
	array_booleano,
	array_caracter,
	desconocido,
} dtipo ;
dtipo tipoTmp;
typedef struct {
	tipoEntrada entrada ;
	char *nombre ;
	dtipo tipoDato ;
        unsigned int parametros ;            /* si entrada = procedimiento */
        unsigned int dimensiones ;           /* si tipoDato = array_... */
        int TamDimen1 ; 		     /* si tipoDato = array_... */	
        int TamDimen2 ; 		     /* si tipoDato = array_... */
} entradaTS ;

typedef struct {
	int atrib ; 			       /* Atributo del s�mbolo (si tiene) */
	char *lexema ; 			       /* Nombre del lexema */
	dtipo tipo ; 			       /* Tipo del s�mbolo */
        unsigned int dimensiones ;           /* si tipoDato = array_... */
        int TamDimen1 ;                      /* si tipoDato = array_... */
        int TamDimen2 ;                      /* si tipoDato = array_... */
  //int numArgumentos;
} atributos ;

atributos att_tmp;

#define YYSTYPE atributos 		/* A partir de ahora, cada s�mbolo tiene una estructura de tipo atributos*/
#define MAX_TS 1000

unsigned int TOPE=0 ; 			/* TOPE de la pila */
unsigned int subProg ; 			/* Indicador de comienzo de bloque de un subprog */
unsigned int dec_param_flag;
/* FLAG de decl de param */
entradaTS TS[MAX_TS] ; 			/* Pila de la tabla de s�mbolos */

int yylineno;					/* Numero de linea */


/*********************  FUNCIONES TABLA SIMBOLOS  ****************************************+
*******************************************************************************************/


void initTS(){
  int i;
  for(i=0;i<MAX_TS;i++){
    TS[i].nombre = 0;
  }
}

char* dtipo2str(dtipo tipo){
	if(tipo == entero)
		return("entero");
	if(tipo == real)
		return("real");
	if(tipo == caracter)
		return("caracter");
	if(tipo == booleano)
		return("booleano");	
	if(tipo == array_entero)
		return("pila entero");
	if(tipo == array_real)
		return("pila real");
	if(tipo == array_caracter)
		return("pila booleano");
	if(tipo == array_booleano)
		return("pila caracter");
	if(tipo == desconocido)
		return("desconocido");
}

void imprimeTS () {
	/* Imprime por pantalla la tabla de simbolos */
	int i;
	int letra;
	for (i=0; i<=TOPE; i++) {
		if (TS[i].entrada==marca)
			printf("<<< MARCA >>>\n");
		if (TS[i].entrada==procedimiento){
			printf("Procedimiento: %s, Tipo: %d, Num. Parametros: %d\n", TS[i].nombre, TS[i].tipoDato, TS[i].parametros);
		}
		if (TS[i].entrada == variable){
			printf("Variable: %s, Tipo: %s\n", TS[i].nombre, dtipo2str(TS[i].tipoDato));
		}
			
		if (TS[i].entrada==parametro)
			printf("Parametro: %s, Tipo: %s\n", TS[i].nombre,dtipo2str(TS[i].tipoDato));
	}
	getchar();

	printf("********************************************************************\n");
}

void buscar_repetidas(char *lexema) {
	/* Miramos que en la tabla de simbolos no exista otro identificador con el mismo lexema*/
	int i;

	/* Comprobar si ya existe otro con el mismo lexema en el mismo
	   bloque */
	for (i=TOPE; TS[i].entrada != marca; i--){

		if (!strcmp(TS[i].nombre, lexema) && TS[i].entrada != parametro) {
			printf ("\nError Semantico en la linea %d: Identificador %s ya esta declarado\n", yylineno, lexema);
			return;
		}
	}
}



//MAL?
int es_repetida(char *lexema) {
	/* Miramos que en la tabla de simbolos no exista otro identificador con el mismo lexema*/
	int i;

	/* Comprobar si ya existe otro con el mismo lexema en el mismo
	   bloque */
	for (i=TOPE; TS[i].entrada != marca; i--){
		if (!strcmp(TS[i].nombre, lexema) && TS[i].entrada != parametro) {
			printf ("\nError Semantico en la linea %d: Identificador %s ya esta declarado\n", yylineno, lexema);
			return 1;
		}
	}
	return 0;
}


int existe(char *lexema) {
	/* Devuelve 1 si esta definida una variable con el nombre especificado
	   o 0 en caso contrario */
	long int temp;
		
	for (temp=TOPE; temp>0;temp--)
		if (TS[temp].entrada == variable && !strcmp(TS[temp].nombre, lexema))
			return 1;

	return 0;
}




int BuscarParametroRepetido (char *lexema) {
	/* Comprobar si ya existe otro parametro con el mismo lexema en el mismo
	   procedimiento*/

	int i;

	for (i=TOPE; TS[i].entrada != procedimiento; i--){
		if (!strcmp(TS[i].nombre, lexema)) {
			printf ("\nError Semantico en la linea %d: Parametro %s esta duplicado\n", yylineno, lexema);
			return 1;
		}
	}
	return 0;
}



/*Porque tipo desconocido??*/
void CuentaParametros () {
	/* Asigna el tipo desconocido al procedimiento y  cuenta cuantos parametros tiene */
	int i;
	int parametros=0;

	for (i=TOPE;TS[i].entrada != procedimiento;i--)
		if (TS[i].entrada == parametro) {
			parametros++;
		}

	TS[i].tipoDato=desconocido;//wtf?
	TS[i].parametros=parametros;
}
void pushEntradaTS(entradaTS* elem){
/* Ojo con tipoTmp, asignar cuando lea el tipo en declaraci�n */
  TOPE++;
  TS[TOPE].entrada = elem->entrada;
  if(elem->nombre != 0) 
    TS[TOPE].nombre = strdup(elem->nombre); 
  else
    TS[TOPE].nombre = 0;

  TS[TOPE].tipoDato = elem->tipoDato;
  TS[TOPE].parametros = elem->parametros;
  TS[TOPE].dimensiones = elem->dimensiones ;
  TS[TOPE].TamDimen1 = elem->TamDimen1;     
  TS[TOPE].TamDimen2 = elem->TamDimen2;     

}
void entradacpy(entradaTS* lvalue,entradaTS* rvalue){

  lvalue->entrada = rvalue->entrada;
  if(rvalue->nombre != 0)
    lvalue->nombre = strdup(rvalue->nombre);
  else
    lvalue->nombre = 0;

  lvalue->tipoDato = rvalue->tipoDato;
  lvalue->parametros = rvalue->parametros;
  lvalue->dimensiones = rvalue->dimensiones ;
  lvalue->TamDimen1 = rvalue->TamDimen1;
  lvalue->TamDimen2 = rvalue->TamDimen2;

}
void atributocpy(atributos* lvalue,atributos* rvalue){

  lvalue->atrib = rvalue->atrib;
  if(rvalue->lexema != 0 && rvalue->lexema!= NULL)
    lvalue->lexema = strdup(rvalue->lexema);
  else
    lvalue->lexema = 0;

  lvalue->tipo = rvalue->tipo;
  lvalue->dimensiones = rvalue->dimensiones ;
  lvalue->TamDimen1 = rvalue->TamDimen1;
  lvalue->TamDimen2 = rvalue->TamDimen2;

}


void IntroIniBloq() {
	/* Inserta una entrada en la tabla de simbolo con una marca */
	/* y copia los parametros del procedimiento como si
	   fueran variables */
  int index;
  unsigned int num_params = 0;
  entradaTS elem;
  entradaTS elem_variable;
  elem.entrada = marca;
  elem.nombre = 0;
  pushEntradaTS(&elem);
  if(subProg == 1){/*Es un bloque de subProg*/
    index = TOPE-1;
    while(TS[index].entrada == parametro){
      /* Hemos encontrado un parametro, incluirlo como variable */
      entradacpy(&elem_variable,&TS[index]);
      elem_variable.entrada = variable;
      pushEntradaTS(&elem_variable);
      index++;
      num_params++;
    }
    if(TS[index].entrada == procedimiento){
      TS[index].parametros = num_params;
    }else{
      printf("\nERROR: Hay algo mal en la TS, no se ha encontrado procedimiento despu�s de los params.\n");
	getchar();
    }
  }

	//MostrarTS();
}

void IntroFinBloq () {
	/* Elimina entradas de la tabla de simbolos hasta que se encuentra
	    una marca de comienzo de bloque o se queda la tabla de simbolos
	   vacia */

	for (;TOPE>=0 && TS[TOPE].entrada!=marca;TOPE--);
	if (TOPE!=0)
		TOPE--;
	//MostrarTS();
	
}

int existeProc (char *lexema) {
/*comprueba que existe un nombre de procedimiento declarado igual al que se le pasa*/
	int i;
	int igual=0;
	for (i=TOPE+1; i>=0 && TS[TOPE].entrada!=marca; i--)
		if (TS[i].entrada == procedimiento && !strcmp(TS[i].nombre, lexema))
			igual=1;
	return igual;
}

int numParametros(char* lexema){
/*Devuelve el numero de parametros de un procedimiento*/
	int i;
	int igual=0;
	for (i=TOPE+1; i>=0; i--)
		if (TS[i].entrada == procedimiento && !strcmp(TS[i].nombre, lexema)){
			return TS[i].parametros;
		}


}

dtipo tipoParametro(int num, char* lexema){
/*Devuelve el tipo de parametro del procedimiento llamado lexema en la posicion num*/
	int i;
	int igual=0;
	for (i=TOPE; i>=0; i--)
		if (TS[i].entrada == procedimiento && !strcmp(TS[i].nombre, lexema)){
			return (TS[i+num].tipoDato);
		}
} 


dtipo get_tipo (char *lexema) {
	/* Devuelve el tipo si esta definida una variable con el nombre lexema
	    */
	long int temp;

	for (temp=TOPE; temp>0 && TS[TOPE].entrada!=marca;temp--)
		if (TS[temp].entrada == variable && !strcmp(TS[temp].nombre, lexema))
			return TS[temp].tipoDato;
}

dtipo tipoArray (dtipo elem) {
	/* Devuelve el tipo de la pila
	    */
	if(es_array(elem)==1){
		if(elem==array_booleano)
			return booleano;
		if(elem==array_entero)
			return entero;
		if(elem==array_real)
			return real;
		if(elem==array_caracter)
			return caracter;
	}
	else{
		return elem;
	}	

}

int es_array(dtipo tipo_array){
	if((tipo_array==array_booleano)||(tipo_array==array_entero)||(tipo_array==array_real)||(tipo_array==array_caracter))
		return 1;
	else
		return 0;
}

dtipo tipoEnArray(dtipo a){
		
		if(a==booleano)
			return array_booleano;
		if(a==entero)
			return array_entero;
		if(a==real)
			return array_real;
		if(a==caracter)
			return array_caracter;

		return a;

}

void TS_InsertaSUBPROG(atributos* att){
  entradaTS entrada_subprog;
  /* ojo, si att.lexema es NULL va a petar */
  if(att->lexema != NULL && att->lexema != 0){
    entrada_subprog.nombre = strdup(att->lexema);
  }else{
    printf("ERROR: Se ha pasado att con lexema no inicializado en TS_InsertaSUBPROG(att)\n");
    getchar();
    exit(0);
  }
  //entrada_subprog.tipoDato = att->tipo;
  entrada_subprog.parametros = 0;
  entrada_subprog.entrada = procedimiento;
  pushEntradaTS(&entrada_subprog);
  //AnyCheck?
}

void TS_InsertaPARAMF(atributos* att){
  entradaTS entrada_paramf;
  entrada_paramf.entrada = parametro;
  if(att->lexema != NULL && att->lexema != 0){
    entrada_paramf.nombre = strdup(att->lexema);
  }else{
    printf("ERROR: Se ha pasado att con lexema no inicializado en TS_InsertaPARAMF(att)\n");
    getchar();
    exit(0);
  }
  entrada_paramf.tipoDato = tipoTmp;
  pushEntradaTS(&entrada_paramf);
  //AnyCheck?
}
