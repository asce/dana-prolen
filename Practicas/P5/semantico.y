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
programa: {initTS();} cabecera_programa bloque {printf("\nAnálisis finalizado.\n"); return 0;};

cabecera_programa: MAIN;

bloque : INICIO {IntroIniBloq();} 
declar_de_variables_locales {/*showNewBlock();*/} 
declar_de_subprogs 
sentencias 
FINBLO {IntroFinBloq();}
;


declar_de_subprogs: declar_de_subprogs declar_subprog | ;

declar_subprog: cabecera_subprograma { subProg = 1; } 
bloque { /*subProg = 0;*/ }
                ;

cabecera_subprograma: PROCED IDENTIFICADOR PARIZ {TS_InsertaSUBPROG(&$2);} declar_parametros PARDER
|PROCED IDENTIFICADOR PARIZ {TS_InsertaSUBPROG(&$2);} PARDER;

declar_parametros: declar_parametros COMA TIPOSIMPLE {tipoTmp = $3.tipo;} iden {TS_InsertaPARAMF(&$5);} 
| TIPOSIMPLE {tipoTmp = $1.tipo;} iden {TS_InsertaPARAMF(&$3);}
| error;//error3


iden: IDENTIFICADOR 
{ 
    atributocpy(&$$,&$1);
    $$.tipo = tipoTmp;
    //en principio es lo mismo dec_flag o no ya que en sentencia se sobreescribe
}

| IDENTIFICADOR CORIZ  expresion CORDER 
{ 
  if(dec_flag){
    atributocpy(&$$,&$1);
    $$.tipo = tipoEnArray(tipoTmp);
    $$.dimensiones = 1;
  if(checkIndexEntero(&$3))
    $$.TamDimen1 = atoi($3.lexema); /* revisar */
    
    //showAtt(&$$);
    //getchar();
  }else{
    atributocpy(&$$,&$1);
    $$.tipo = tipoEnArray(tipoTmp);
    $$.dimensiones = 1;
  if(checkIndexEntero(&$3))
    $$.TamDimen1 = atoi($3.lexema); /* revisar */
    //showAtt(&$$);
    //getchar();
  }
} 

| IDENTIFICADOR CORIZ  expresion COMA expresion CORDER 
{ 
  if(dec_flag){
    atributocpy(&$$,&$1);
    $$.tipo = tipoEnArray(tipoTmp);
    $$.dimensiones = 2;
    //if(checkIndexEntero(&$3))
    $$.TamDimen1 = atoi($3.lexema); /* revisar */
    //if(checkIndexEntero(&$5))
    $$.TamDimen2 = atoi($5.lexema); /* revisar */
    //showAtt(&$$);
    //getchar();
  }else{
    atributocpy(&$$,&$1);
    $$.tipo = tipoEnArray(tipoTmp);
    $$.dimensiones = 2;
    //if(checkIndexEntero(&$3))
    $$.TamDimen1 = atoi($3.lexema); /* revisar */
    //if(checkIndexEntero(&$5))
    $$.TamDimen2 = atoi($5.lexema); /* revisar */
    //showAtt(&$$);
    //getchar();
  }
}
;

declar_de_variables_locales: INICIOV variables_locales FINV | ;
variables_locales:variables_locales cuerpo_decla_variables
	|cuerpo_decla_variables | error;

cuerpo_decla_variables: TIPOSIMPLE {tipoTmp = $1.tipo;dec_flag=1;} lista_variables {dec_flag=0;} PYC;

lista_variables: lista_variables COMA iden {if(dec_flag)TS_InsertaVAR(&$3);} | iden {if(dec_flag)TS_InsertaVAR(&$1);} | error ;//sincroniza con COMA o PYC

sentencias: sentencias sentencia | sentencia;

sentencia: bloque
           |sentencia_asignacion
	   | sentencia_if
           | sentencia_while
	   | sentencia_entrada
	   | sentencia_salida
| procedimiento {checkProced(&$1,&$$);}
           | sentencia_case | error;

sentencia_asignacion: iden {checkScope(&$1,&$1); } ASIG expresion {
checkEqualTypeAsig(&$1,&$4);
 if(es_array($1.tipo) && es_array($4.tipo)){
   checkEqualDimenArray(&$1,&$4);
   //showAtt(&$1);
   //showAtt(&$4);
 }

} PYC;

expresion: PARIZ expresion PARDER {atributocpy(&$$,&$2);}
| OPB_ADD expresion %prec OPU{
  atributocpy(&$$,&$2);
  /*AnyCheck?*/
  /* si está activo el flag de array dar error para $1.atrib=2 ( - ) */
  if(array_flag){
    checkSignArray(&$1);//TODO
  }

} 
| expresion OPB_OR expresion{
  atributocpy(&$$,&$1);
  if(check_OPB_OR(&$1,&$3)==0) $$.tipo=desconocido;
  $$.lexema = "_";
}
| expresion OPB_AND expresion{
  atributocpy(&$$,&$1);
  if(check_OPB_AND(&$1,&$3)==0) $$.tipo=desconocido;
  $$.lexema = "_";
}
| expresion OPB_IG expresion{
  atributocpy(&$$,&$1);
  if(check_OPB_IG(&$1,&$3)==0)$$.tipo=desconocido;
  $$.lexema = "_";
}
| expresion OPB_REL expresion{
  atributocpy(&$$,&$1);
  if(check_OPB_REL(&$1,&$3)==0)
    $$.tipo=desconocido;
  else{
    $$.tipo=booleano;
  }
  $$.lexema = "_";
}
| expresion OPB_ADD expresion{
  atributocpy(&$$,&$1);
  if(check_OPB_ADD(&$1,&$3)==0 ||checkEqualDimenArray(&$1,&$3)==0)
    $$.tipo=desconocido;
  $$.lexema = "_";
}
| expresion OPB_MUL expresion{
  atributocpy(&$$,&$1);
  if(check_OPB_MUL(&$1,&$3)==0) {$$.tipo=desconocido;}
  if($2.atrib == 1){ /*  **  */
    if(checkArrayMulDimension(&$1,&$3)==0)
      {$$.tipo=desconocido;}
    $$.TamDimen1 = $1.TamDimen1;
    $$.TamDimen2 = $3.TamDimen2;
    //showAtt(&$$);
    //getchar();
  }else{
    if(checkEqualDimenArray(&$1,&$3)==0){
      $$.tipo=desconocido;
    }else{
      //printf("Opp entre arrays\n");
      $$.TamDimen1 = $1.TamDimen1;
      $$.TamDimen2 = $1.TamDimen2;
      //showAtt(&$$);getchar();
    }
  }
  $$.lexema = "_";
}
| OPU expresion 
{ if(checkBoolean(&$2)==0)
    $$.tipo=desconocido; 
  else $$.tipo=$2.tipo;
}
| iden 
{
 checkScope(&$1,&$$);
 if($$.dimensiones == $1.dimensiones){
   $$.tipo=tipoArray($$.tipo);
 }//else if($$.dimensiones == $1.dimensiones+1){
   //
 //}
}
| CONSTANTE{atributocpy(&$$,&$1);} 
| CONSTANTE_E{atributocpy(&$$,&$1);}
| CARACTER{atributocpy(&$$,&$1);}
| agregados{ /*que no sea index de array o se pase a proc*/ }
| error;

procedimiento: IDENTIFICADOR PARIZ 
{call_procedure_flag=1;

} 
lista_expresiones PARDER 
{
call_procedure_flag=0;
 checkCallProc(&$1,&$$);

} PYC
|IDENTIFICADOR PARIZ PARDER {checkCallProcWithoutArgs(&$1,&$$);}PYC
;

agregados: INICIO lista_expresiones FINBLO;

lista_expresiones: lista_expresiones COMA expresion 
{if(call_procedure_flag){
    linkAtt(&$3);
  }
} 
| expresion
{if(call_procedure_flag){
    linkAtt(&$1);
  }
}
;

sentencia_if: alternativa_doble	| alternativa_simple;

alternativa_simple: if_expresion_sentencia;

alternativa_doble: if_expresion_sentencia ELSE sentencia;

if_expresion_sentencia: IF expresion {checkBoolean(&$2);} sentencia;

sentencia_while: WHILE PARIZ expresion {checkBoolean(&$3);} PARDER sentencia;

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
