%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

  /* Para que yyerror se pueda invocar en prueba.l */
  void yyerror(char * msg);
  /* Para saber la línea actual, tb podemos usar yylineno usando la opción -l de flex */
  int linea_actual = 1;

%}

/** Para uso de mensajes de error sintáctico con BISON >= 2.1
 ** para BISON < 2.1 usar
 ** #define YYERROR_VERBOSE
 **
 ** No tener en cuenta para usar mensajes de error con mes y mes2
 **/

%error-verbose

 /** Declaración de los nombres simbólicos de los tokens **/
 %token NOMBRE VERBO
 %token NOMBRE_PROPIO
 %token ARTICULO ARTICULO_A
 %token DESCONOCIDO

%%

 /** Producciones **/

frase : sintagma_nominal sintagma_predicado;
sintagma_nominal : ARTICULO NOMBRE | NOMBRE_PROPIO ;
sintagma_predicado : VERBO modificador objeto_directo;
objeto_directo : sintagma_nominal ;
modificador : ARTICULO_A |;

%%

 /** Incluimos el fichero generado por el lex que implementa la funcion yylex **/
#ifdef DOSWINDOWS
#include "lexyy.c"
#else
#include "lex.yy.c"
#endif

 /** implementamos la función yyerror **/

void yyerror(char* msg){

  fprintf(stderr,"[Linea %d] %s\n",linea_actual, msg);

}
