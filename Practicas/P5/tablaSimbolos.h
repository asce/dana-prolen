#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ListaInt.h"



/********************************  ESTRUCTURAS DE DATOS *********************************/
/****************************************************************************************/

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
	vacio, //No tiene tipo de dato: void
	desconocido,
} dtipo ;

typedef struct {
	tipoEntrada entrada ;
	char *nombre ;
	dtipo tipoDato ;
        unsigned int parametros ;            /* si entrada = procedimiento */
        unsigned int dimensiones ;           /* si tipoDato = array_... */
        int TamDimen1 ; 		     /* si tipoDato = array_... */	
        int TamDimen2 ; 		     /* si tipoDato = array_... */
  node lista_parametros;                     /* si entrada = procedimiento */
} entradaTS ;
//lista parametros tiene un numero basura y un puntero a la lista de parametros del
//procedimiento

typedef struct {
	int atrib ; 			       /* Atributo del símbolo (si tiene) */
	char *lexema ; 			       /* Nombre del lexema */
	dtipo tipo ; 			       /* Tipo del símbolo */
        unsigned int dimensiones ;           /* si tipoDato = array_... */
        int TamDimen1 ;                      /* si tipoDato = array_... */
        int TamDimen2 ;                      /* si tipoDato = array_... */
  char* expr_tmp;
//int numArgumentos;
} atributos ;


/****************************   DECLARACIONES GLOBALES *****************************/
/***********************************************************************************/


#define YYSTYPE atributos 		/* A partir de ahora, cada símbolo tiene una estructura de tipo atributos*/
#define MAX_TS 1000
entradaTS TS[MAX_TS] ; 			/* Pila de la tabla de símbolos */
dtipo tipoTmp;
node params_last_proc_call = {0,NULL};
int scope_index_TS;
unsigned int TOPE=0 ; 			/* TOPE de la pila */
unsigned int last_proc_index;
unsigned int subProg ; 			/* Indicador de comienzo de bloque de un subprog */
unsigned int dec_flag = 0;
unsigned int array_flag = 0; //TODO
unsigned int call_procedure_flag = 0;
unsigned int main_flag = 1;
unsigned int read_flag = 0;
unsigned int iden_fun_flag = 0;
int yylineno;					/* Numero de linea */


/********************** CABECERA FUNCIONES *********************************************/
/****************************************************************************************/


void initEntradaTS(entradaTS* e);
void initTS();
char* dtipo2str(dtipo tipo);
char* dtipo2ctipostr(dtipo tipo);
char* tipoEntrada2str(tipoEntrada e);
void showTS();
void pushEntradaTS(entradaTS* elem);
void entradacpy(entradaTS* lvalue,entradaTS* rvalue);
void atributocpy(atributos* lvalue,atributos* rvalue);
void IntroIniBloq();
void showEntrada(entradaTS * e);
void showNewBlock();
void IntroFinBloq ();
dtipo tipoArray (dtipo elem);
int es_array(dtipo tipo_array);
dtipo tipoEnArray(dtipo a);
void pushMarca();
void TS_InsertaSUBPROG(atributos* att);
void TS_InsertaPARAMF(atributos* att);
void TS_InsertaVAR(atributos* att);
/**                                                                                                                                              
 * Devuelve 1 si existe un identificador 'iden' en el bloque actual y 0 en otro caso                                                             
 */
int declaredIden(char* iden);
void showAtt(atributos* att);
void getAttFromTS(atributos* att,int index);
/**                                                                                                                                              
 * Devuelve indice de TS si se encuentra iden en el ambito y 0 en otro caso                                                                      
 * (en la posicion 0 siempre hay una marca)                                                                                                      
 */
int inScope(atributos* query,atributos* found);
void setNotFoundAtt(atributos* att,char* name);
int checkScope(atributos* att,atributos* found);
void checkProced(atributos* att,atributos* found);
/** ED y Func. para errores en llamadas a procedimientos **/

void linkAtt(atributos* att);
void checkSignArray(atributos* attOPB_ADD);
int check_OPB_OR(atributos* op1,atributos* op2);
int check_OPB_AND(atributos* op1,atributos* op2);
int check_OPB_IG(atributos* op1,atributos* op2);
int check_OPB_REL(atributos* op1,atributos* op2);
int check_OPB_ADD(atributos* op1,atributos* op2);
int check_OPB_MUL(atributos* op1,atributos* op2);
int checkEqualType(atributos* op1,atributos* op2);
int checkEqualTypeAsig(atributos* op1,atributos* op2);
int checkEqualDimenArray(atributos* op1,atributos* op2);
int checkArrayMulDimension(atributos* op1,atributos* op2);
int checkIndexEntero(atributos* att);
int checkBoolean(atributos* att);
void checkCallProc(atributos* att,atributos* found);
void checkCallProcWithoutArgs(atributos* att,atributos* found);
int checkProcCallArgs(atributos* att,node* l1,node*l2);
int checkAccessArray(atributos* att1, atributos* att2);
void showNodesTypes (node* start) ;


/*********************  FUNCIONES TABLA SIMBOLOS  *****************************************/
/*******************************************************************************************/



void initEntradaTS(entradaTS* e){
  e->nombre = 0;
  e->lista_parametros.next = NULL;
}

void initTS(){
  int i;
  for(i=0;i<MAX_TS;i++){
    initEntradaTS(&TS[i]);
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
		return("array_entero");
	if(tipo == array_real)
		return("array_real");
	if(tipo == array_booleano)
		return("array_booleano");
	if(tipo == array_caracter)
		return("array_caracter");
	if(tipo == desconocido)
		return("desconocido");
        if(tipo == vacio)
	  return("void");

}

char* dtipo2ctipostr(dtipo tipo){
  dtipo t = tipoArray(tipo);
  if(t == entero)
    return("int");
  if(t == real)
    return("double");
  if(t == caracter)
    return("char");
  if(t == booleano)
    return("int");
  if(t == vacio)
    return("void");
  return "desconocido";
}
char* tipoEntrada2str(tipoEntrada e){
  switch(e){
  case marca:
    return "marca";
    break;
  case procedimiento:
    return "procedimiento";
    break;
  case variable:
    return "variable";
    break;
  case parametro:
    return "parametro";
    break;
  default:
    return "TRASH";
  }
}

void showTS(){
  int i;
  printf("Contenido de la TS:\n");
  for(i=TOPE;i>=0;i--){
    if(TS[i].entrada!=marca){
      showEntrada(&TS[i]);
    }else{
      printf("<<< MARCA >>>\n");
    }
  }
}

void pushEntradaTS(entradaTS* elem){
/* Ojo con tipoTmp, asignar cuando lea el tipo en declaración */
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
  if(rvalue->expr_tmp != 0 && rvalue->expr_tmp!= NULL)
    lvalue->expr_tmp = strdup(rvalue->expr_tmp);

}


void IntroIniBloq() {
	/* Inserta una entrada en la tabla de simbolo con una marca */
	/* y copia los parametros del procedimiento como si
	   fueran variables */
  int index;
  unsigned int num_params = 0;
  entradaTS elem_variable;
  initEntradaTS(&elem_variable);

    pushMarca();
  if(subProg == 1){/* subProg ==1, Es un bloque de subProg*/
    index = TOPE-1;
    while(TS[index].entrada == parametro){
      /* Hemos encontrado un parametro, incluirlo como variable */
      entradacpy(&elem_variable,&TS[index]);
      elem_variable.entrada = variable;
      pushEntradaTS(&elem_variable);
      //TODO Enlaza param a Func!
      index--;
      //num_params++;
    }
    if(index!=last_proc_index){
      printf("\nWARNING: Hay algo mal en la TS, no se ha encontrado procedimiento después de los params.\n");
      //showEntrada(&TS[index]);
      //imprimeTS();
      getchar();
    }else{
      index++;
      while(TS[index].entrada == parametro){
	addNode(&TS[last_proc_index].lista_parametros,TS[index].tipoDato);
	index++;
      }
    }
  }
  subProg=0;
	//MostrarTS();
}

void showEntrada(entradaTS * e){


  printf("------- Entrada values: -------\n");
  printf("Entrada: %s\nnombre: %s\ntipoDato: %s\nparametros: %i\nDimens: %i\nd1: %i\nd2: %i\n",
         tipoEntrada2str(e->entrada),e->nombre,dtipo2str(e->tipoDato),e->parametros,e->dimensiones,e->TamDimen1,e->TamDimen2);
  if(e->entrada==procedimiento)
    showNodes(e->lista_parametros.next);

}
void showNewBlock(){
  printf("-------------------------------------- NUEVO BLOQUE --------------------------------------\n");
  showTS();
  getchar();
}

void IntroFinBloq () {
	/* Elimina entradas de la tabla de simbolos hasta que se encuentra
	    una marca de comienzo de bloque o se queda la tabla de simbolos
	   vacia */

	for (;TOPE>=0 && TS[TOPE].entrada!=marca;TOPE--);
	if (TOPE!=0){
	  if(TS[TOPE].lista_parametros.next!=0 && TS[TOPE].lista_parametros.next!=NULL){
	    freeNode(TS[TOPE].lista_parametros.next);
	  }
	  TOPE--;
	
	}
	//MostrarTS();

	//printf("--------------------------------------Finalizado bloque--------------------------------------\n");
	//showTS();
	//getchar();
}

dtipo tipoArray (dtipo elem) {
	/* Devuelve el tipo del array
	    */
		if(elem==array_booleano)
			return booleano;
		if(elem==array_entero)
			return entero;
		if(elem==array_real)
			return real;
		if(elem==array_caracter)
			return caracter;
		return elem;

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
void pushMarca(){
  entradaTS elem;
  initEntradaTS(&elem);
  elem.entrada = marca;
  elem.nombre = 0;
  pushEntradaTS(&elem);
}
void TS_InsertaSUBPROG(atributos* att){
  entradaTS entrada_subprog;
  initEntradaTS(&entrada_subprog);

  /* ojo, si att.lexema es NULL va a petar */
  if(att->lexema != NULL && att->lexema != 0){
    if(declaredIden(att->lexema)){
      printf("[Linea %i] ERROR SEMÁNTICO: Ya existe \"%s\" en el bloque.\n",yylineno,att->lexema);
      //getchar();
      return;
    }
    entrada_subprog.nombre = strdup(att->lexema);
  }else{
    showAtt(att);
    printf("WARNING: Se ha pasado att con lexema no inicializado en TS_InsertaSUBPROG(att)\n");
    //getchar();
    exit(0);
  }
  //entrada_subprog.tipoDato = att->tipo;
  entrada_subprog.tipoDato = vacio;
  entrada_subprog.parametros = 0;
  entrada_subprog.entrada = procedimiento;
  pushEntradaTS(&entrada_subprog);
  last_proc_index = TOPE;
  //AnyCheck?
}

void TS_InsertaPARAMF(atributos* att){
  entradaTS entrada_paramf;
  initEntradaTS(&entrada_paramf);
  entrada_paramf.entrada = parametro;
  if(att->lexema != NULL && att->lexema != 0){
    entrada_paramf.nombre = strdup(att->lexema);
  }else{
    printf("WARNING: Se ha pasado att con lexema no inicializado en TS_InsertaPARAMF(att)\n");
    //getchar();
    exit(0);
  }
  entrada_paramf.tipoDato = att->tipo;
  entrada_paramf.dimensiones = att->dimensiones;
  entrada_paramf.TamDimen1 = att->TamDimen1;
  entrada_paramf.TamDimen2 = att->TamDimen2;
  pushEntradaTS(&entrada_paramf);
  //AnyCheck?                                                                                                       
}
void TS_InsertaVAR(atributos* att){
  entradaTS entrada_var;
  initEntradaTS(&entrada_var);

  entrada_var.entrada = variable;
  if(att->lexema != NULL && att->lexema != 0){
    if(declaredIden(att->lexema)){
      printf("[Linea %i] ERROR SEMÁNTICO: Ya existe \"%s\" en el bloque.\n",yylineno,att->lexema);
      //getchar();
      return;
    }
    entrada_var.nombre = strdup(att->lexema);
  }else{
    printf("WARNING: Se ha pasado att con lexema no inicializado en TS_InsertaVAR(att)\n");
    //getchar();
    exit(0);
  }
  entrada_var.tipoDato = att->tipo;
  entrada_var.dimensiones = att->dimensiones;
  entrada_var.TamDimen1 = att->TamDimen1;
  entrada_var.TamDimen2 = att->TamDimen2;
  pushEntradaTS(&entrada_var);
  //AnyCheck?
}
/**
 * Devuelve 1 si existe un identificador 'iden' en el bloque actual y 0 en otro caso 
 */
int declaredIden(char* iden){
  int i;
  for(i=TOPE;i>=0 && TS[i].entrada!=marca;i--){
    if(TS[i].nombre!=0 && TS[i].nombre!=NULL){
      if(strcmp(TS[i].nombre,iden)==0) //ident. 'iden' exists
	return 1;
    }else{
      printf("\nWARNING: Algo va mal en TS, hay una entrada sin nombre\n");
      //getchar();
      exit(0);
    }
  }
  return 0;
}

void showAtt(atributos* att){
  printf("Atts values:\n");
  printf("atrib: %i\nlexema: %s\ntipo: %i\nDimens: %i\nd1: %i\nd2: %i\n",
	 att->atrib,att->lexema,att->tipo,att->dimensiones,att->TamDimen1,att->TamDimen2);

}
void getAttFromTS(atributos* att,int index){
  att->atrib=-1;
  att->lexema=strdup(TS[index].nombre);
  att->expr_tmp = strdup(TS[index].nombre);
  att->tipo=TS[index].tipoDato;
  if(es_array(att->tipo)==0){
    att->dimensiones=-1;
    att->TamDimen1=-1;
    att->TamDimen2=-1;
  }else{
    att->dimensiones=TS[index].dimensiones;
    att->TamDimen1=TS[index].TamDimen1;
    att->TamDimen2=TS[index].TamDimen2;
  }
}
/**
 * Devuelve indice de TS si se encuentra iden en el ambito y 0 en otro caso
 * (en la posicion 0 siempre hay una marca)
 */
int inScope(atributos* query,atributos* found){
  int i;
  char* iden = strdup(query->lexema); 
  for(i=TOPE;i>=0;i--){
    if(TS[i].nombre!=0 && TS[i].nombre!=NULL){
      if(strcmp(TS[i].nombre,iden)==0){ //ident. 'iden' exists
	getAttFromTS(found,i);
	return i;
      }
    }else if(TS[i].entrada!=marca){
      printf("\nWARNING: Algo va mal en TS, hay una entrada sin nombre\n");
      //getchar();
      exit(0);
    }
  }
  setNotFoundAtt(found,iden);
  return 0;
}
void setNotFoundAtt(atributos* att,char* name){
  att->atrib=-1;
  att->lexema=strdup(name);
  att->tipo=desconocido;
  att->dimensiones=-1;
  att->TamDimen1=-1;
  att->TamDimen2=-1;
}

int checkScope(atributos* att,atributos* found){
  //atributos att_found;
  int indexTS;
  indexTS = inScope(att,found);
  if(att->lexema != NULL && att->lexema != 0){
    if(indexTS==0){
      printf("[Linea %i] ERROR SEMÁNTICO: \"%s\" no se ha declarado en el ámbito.\n",yylineno,att->lexema);
      //getchar();
      att->tipo = desconocido;
      return 0;
    }else{//Está en el ámbito
      //¡¡¡Y su valor está en found!!!
      //att->tipo = tipoScope;
      //att->dimensiones = TS[indexTS].dimensiones;
      //att->TamDimen1 = TS[indexTS].TamDimen1;
      //att->TamDimen2 = TS[indexTS].TamDimen2;
      if(es_array(att->tipo)){
	//showAtt(att);
	//getchar();
      }
      return indexTS;
    }
  }else{
    printf("WARNING: Se ha pasado att con lexema no inicializado en checkScope(att)\n");
    //getchar();
    exit(0);
  }

}

void checkProced(atributos* att,atributos* found){
  char* iden;
  int i;
  if(att->lexema==NULL ||att->lexema ==0){
    printf("WARNING: Se ha pasado atributo sin lexema en checkProced\n");
    return;
  }
  i = inScope(att,found);
  if(i==0){
      printf("[Linea %i] ERROR SEMÁNTICO: \"%s\" no se ha declarado en el ámbito.\n",yylineno,att->lexema);
      //getchar();
      return;
  }else{
    if(TS[i].entrada!=procedimiento){
      printf("[Linea %i] ERROR SEMÁNTICO: \"%s\" no se ha declarado en el ámbito como procedimiento.\n",yylineno,att->lexema);
    }else{
      /* Gestion parametros : tipo y numero */
    }

  }
}

/** ED y Func. para errores en llamadas a procedimientos **/

void linkAtt(atributos* att){
  //  procedure_att_end_pointer->next = atributecpy(att);
  addNode(&params_last_proc_call,att->tipo);
  //printf("Linking ...\n");
  //showAtt(att);
  //printf("\n");
  //getchar();
}
//TODO Need Fix?
void checkSignArray(atributos* attOPB_ADD){
    if(attOPB_ADD->atrib==2){ // Signo -
      printf("[Linea %i] ERROR SEMÁNTICO: No se permite un indice negativo en array.\n",yylineno);
    }else if(attOPB_ADD->atrib!=1){
      printf("WARNING en linea %i: No se reconoce el signo del indice del array pasado en checkSignArray",yylineno);
    }
}
int check_OPB_OR(atributos* op1,atributos* op2){

  int valid = checkEqualType(op1,op2);;
  if(op1->tipo!=booleano){
    printf("[Linea %i] ERROR SEMÁNTICO: El op1 de OPB_OR debe ser booleano\n",yylineno);
    valid = 0;
  }
  if(op2->tipo!=booleano){
    printf("[Linea %i] ERROR SEMÁNTICO: El op2 de OPB_OR debe ser booleano\n",yylineno);
    valid = 0;
  }
  return valid;
}
int check_OPB_AND(atributos* op1,atributos* op2){
  int valid = checkEqualType(op1,op2);
  if(op1->tipo!=booleano){
    printf("[Linea %i] ERROR SEMÁNTICO: El op1 de OPB_AND debe ser booleano\n",yylineno);
    valid = 0;
  }
  if(op2->tipo!=booleano){
    printf("[Linea %i] ERROR SEMÁNTICO: El op2 de OPB_AND debe ser booleano\n",yylineno);
    valid = 0;
  }
  return valid;

}
int check_OPB_IG(atributos* op1,atributos* op2){
  int valid  = checkEqualType(op1,op2);
  if(op1->tipo!=entero && op1->tipo!=real){
    printf("[Linea %i] ERROR SEMÁNTICO: El op1 de OPB_IG debe ser entero o real\n",yylineno);
    valid = 0;
  }
  if(op2->tipo!=entero && op2->tipo!=real){
    printf("[Linea %i] ERROR SEMÁNTICO: El op2 de OPB_IG debe ser entero o real\n",yylineno);
    valid = 0;
  }
  return valid;

}
//TODO
int check_OPB_REL(atributos* op1,atributos* op2){
  int valid = checkEqualType(op1,op2);
  if(op1->tipo!=entero && op1->tipo!=real){
    printf("[Linea %i] ERROR SEMÁNTICO: El op1 de OPB_REL debe ser entero o real\n",yylineno);
    valid = 0;
  }
  if(op2->tipo!=entero && op2->tipo!=real){
    printf("[Linea %i] ERROR SEMÁNTICO: El op2 de OPB_REL debe ser entero o real\n",yylineno);
    valid = 0;
  }
  return valid;

}
int check_OPB_ADD(atributos* op1,atributos* op2){
  int valid = checkEqualType(op1,op2);
  if(op1->tipo!=entero && op1->tipo!=real && op1->tipo!=array_entero && op1->tipo!=array_real){
    printf("[Linea %i] ERROR SEMÁNTICO: El op1 de OPB_ADD debe ser entero,array_entero,real o array_real\n",yylineno);
    valid = 0;
  }
  if(op2->tipo!=entero && op2->tipo!=real && op2->tipo!=array_entero && op2->tipo!=array_real){
    printf("[Linea %i] ERROR SEMÁNTICO: El op2 de OPB_ADD debe ser entero,array_entero,real o array_real\n",yylineno);
    valid = 0;
  }
  return valid;

}

int check_OPB_MUL(atributos* op1,atributos* op2){
  int valid = checkEqualType(op1,op2);

  if(op1->tipo!=entero && op1->tipo!=real && op1->tipo!=array_entero && op1->tipo!=array_real){
    printf("[Linea %i] ERROR SEMÁNTICO: El op1 de OPB_MUL debe ser entero,array_entero,real o array_real\n",yylineno);
    valid = 0;
  }
  if(op2->tipo!=entero && op2->tipo!=real && op2->tipo!=array_entero && op2->tipo!=array_real){
    printf("[Linea %i] ERROR SEMÁNTICO: El op2 de OPB_MUL debe ser entero,array_entero,real o array_real\n",yylineno);
    valid = 0;
  }
  return valid;
}

int checkEqualType(atributos* op1,atributos* op2){
  if(op1->tipo==op2->tipo){
    return 1;
  }else if(tipoArray(op1->tipo)!=tipoArray(op2->tipo)){
    printf("[Linea %i] ERROR SEMÁNTICO: Los tipos de la expresión no coinciden. ",yylineno);
    printf("Los operandos son %s (op1): %s y %s (op2): %s\n",op1->lexema,dtipo2str(op1->tipo),op2->lexema,dtipo2str(op2->tipo));
    return 0;
  }else{//Alguno de los dos es array pero del mismo tipo
    return 1;
 }
}
int checkEqualTypeAsig(atributos* op1,atributos* op2){
  if(op1->tipo==op2->tipo){
    return 1;
  }else if(tipoArray(op1->tipo)!=tipoArray(op2->tipo)){
    printf("[Linea %i] ERROR SEMÁNTICO: Los tipos de la asignación no coinciden. ",yylineno);
    printf(" %s (dest): %s y %s (expr): %s\n",op1->lexema,dtipo2str(op1->tipo),op2->lexema,dtipo2str(op2->tipo));
    return 0;
  }else{//Alguno de los dos es array pero del mismo tipo                          
   

  }
}


 int checkEqualDimenArray(atributos* op1,atributos* op2){
   int valid=1;
   //printf("En equal Dimen Array\n");getchar();
   if(es_array(op1->tipo) && es_array(op2->tipo)){
     //printf("Ambos son Arrays\n");getchar();
   if(op1->dimensiones!=op2->dimensiones ||
      op1->TamDimen1!=op2->TamDimen1 ||
      op1->TamDimen2!=op2->TamDimen2){
     printf("[Linea %i] ERROR SEMÁNTICO: Las dimensiones de los array %s y %s no coinciden.\n",yylineno,op1->lexema,op2->lexema);valid=0;
     // showAtt(op1);showAtt(op2);
   }
   }
   return valid;
 }
int checkArrayMulDimension(atributos* op1,atributos* op2){
  int valid=1;
  //printf("En checkArrayMulDimension\n");
  if(es_array(op1->tipo) && es_array(op2->tipo)){
    if(op1->TamDimen2!=op2->TamDimen1){
      printf("[Linea %i] ERROR SEMÁNTICO: En la multiplic. de arrays (**) el número de filas del primer operando debe coincidir con el número de columnas del segundo.\n",yylineno);
      valid=0;}
    else{//printf("Valid\n");getchar();TODO
      /* op1->TamDimen2==op2->TamDimen1  */
    }
  }else{
    printf("[Linea %i] ERROR SEMÁNTICO: La multiplicación de arrays (**) solo se puede aplicar entre dos arrays.\n",yylineno);valid=0;
  }
  return valid;
}

int checkIndexEntero(atributos* att){
  if(att->tipo==entero){
    return 1;
  }else{
    printf("[Linea %i] ERROR SEMÁNTICO: El tipo del indice de un array debe ser entero, se ha encontrado tipo %s.\n",yylineno,dtipo2str(att->tipo));
    return 0;
  }
}
int checkBoolean(atributos* att){
  if(att->tipo==booleano){
    return 1;
  }else{
    printf("[Linea %i] ERROR SEMÁNTICO: Se esperaba un tipo booleano y se ha encontrado una expresión de tipo %s.\n",yylineno,dtipo2str(att->tipo));
    return 0;
  }
}
void checkCallProc(atributos* att,atributos* found){
  int indexTS = inScope(att, found);
  if(indexTS){
    if(TS[indexTS].entrada == procedimiento){
      checkProcCallArgs(att,TS[indexTS].lista_parametros.next,params_last_proc_call.next); 
    }else{
      printf("WARNING: en checkCallProcWithoutArgs, metodo inScope podría estar mal ...\n");
      getchar();
    }
  }
      freeNode(params_last_proc_call.next);//getchar();
      params_last_proc_call.next=NULL;

}
void checkCallProcWithoutArgs(atributos* att,atributos* found){
  int indexTS = inScope(att,found);
  if(indexTS){
    if(TS[indexTS].entrada == procedimiento){
      if(TS[indexTS].parametros != 0){
	printf("[Linea %i] ERROR SEMÁNTICO: El número de parámetros de %s no es correcto.\n",yylineno,att->lexema);
      }
    }else{
      printf("WARNING: en checkCallProcWithoutArgs, metodo inScope podría estar mal ...\n");
      getchar();
    }
  }

}

int checkProcCallArgs(atributos* att,node* l1,node*l2){
  int equal = isEqualNodeList(l1,l2);
  if(equal == 0){
    printf("[Linea %i] ERROR SEMÁNTICO: Llamada a procedimiento erronea.\n",yylineno);
    printf("Se esperaba %s (",att->lexema);
    showNodesTypes(l1);
    printf(")");
    printf(" y se ha encontrado %s (",att->lexema);
    showNodesTypes(l2);
    printf(")\n");
  }
  return equal;
}

int checkAccessArray(atributos* att1, atributos* att2){
  //TODO
  //en rango filas
  //en rango columnas
  // comprobación de tipos
  return 1;
}

void showNodesTypes (node* start) {
  node* cur;
  for (cur = start; cur != NULL; cur = cur->next) {

    printf(" %s",dtipo2str(cur->number));
    if(cur->next!=NULL)
      printf(",");
  }
  //printf("\n");
}


int checkIntOrChar(atributos* att){

  if(att->tipo==entero || att->tipo==caracter){
    return 1;
  }else{
    printf("[Linea %i] ERROR SEMÁNTICO: Se esperaba un tipo entero o caracter y se ha encontrado una expresión de tipo %s.\n",yylineno,dtipo2str(att->tipo));
    return 0;
  }





}
