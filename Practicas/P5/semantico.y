%{

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "traduccion.h"

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
programa: 
{
initTS();
  openFiles("out.c");
} 
cabecera_programa 
bloque 
{
printf("\nAnálisis finalizado.\n");
 closeFiles(); 
return 0;
};

cabecera_programa: MAIN;

bloque : INICIO {IntroIniBloq();if(main_flag==0)writeFout("\n{\n");} 
declar_de_variables_locales 
{
  if(main_flag==1){
    writeMain();
    main_flag=0;
  }

  if(actual_file==MAIN_FILE)
    switch_actual_file(); 
}
declar_de_subprogs
{
  if(actual_file==FUN_FILE && fun_level == 0)
    switch_actual_file(); 
} 
sentencias 
FINBLO {IntroFinBloq();writeFout("\n}\n");}
;


declar_de_subprogs: declar_de_subprogs declar_subprog | ;

declar_subprog:
{iden_fun_flag=1;fun_level++;} 
cabecera_subprograma 
{ subProg = 1; } 
bloque 
{ /*subProg = 0;*/ fun_level--;}
;

cabecera_subprograma: PROCED IDENTIFICADOR PARIZ 
{
TS_InsertaSUBPROG(&$2);
 char str_proce_dec[255];
 sprintf(str_proce_dec,"void %s ( ",$2.lexema);

 writeFout(str_proce_dec);

} 
declar_parametros PARDER
{
  writeFout(")\n");
}
|PROCED IDENTIFICADOR PARIZ {TS_InsertaSUBPROG(&$2);} PARDER
{
  char str_proce_dec[255];
  sprintf(str_proce_dec,"void %s ()",$2.lexema);
  writeFout(str_proce_dec);

}
;

declar_parametros: 
declar_parametros COMA TIPOSIMPLE 
{
  writeFout(",");
  writeFout(dtipo2ctipostr($3.tipo));
  //printf("%i : %s\n",$3.tipo,dtipo2ctipostr($3.tipo));
  //getchar();
tipoTmp = $3.tipo;

} iden {writeFout($5.lexema);TS_InsertaPARAMF(&$5);} 
| TIPOSIMPLE {tipoTmp = $1.tipo;} iden 
{
  writeFout(dtipo2ctipostr($1.tipo));
  writeFout($3.lexema);
TS_InsertaPARAMF(&$3);

}
| error;//error3


iden: IDENTIFICADOR 
{ 
    atributocpy(&$$,&$1);
    $$.tipo = tipoTmp;
    if(dec_flag==1){
      if(main_flag==0)
      writeFout($1.lexema);
      else writeGlobal($1.lexema);
      
    }

    //en principio es lo mismo dec_flag o no ya que en sentencia se sobreescribe
}

| IDENTIFICADOR CORIZ  expresion CORDER 
{ 
  if(dec_flag==1){
    atributocpy(&$$,&$1);
    $$.tipo = tipoEnArray(tipoTmp);
    $$.dimensiones = 1;
  if(checkIndexEntero(&$3))
    $$.TamDimen1 = atoi($3.lexema); /* revisar */
  char tmp[256];
  sprintf(tmp,"%s[%i]",$1.lexema,$$.TamDimen1);
  if(main_flag==0)
    writeFout(tmp);
  else writeGlobal(tmp);
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
    char tmp[256];
    sprintf(tmp,"%s[%i][%i]",$1.lexema,$$.TamDimen1,$$.TamDimen2);
  if(main_flag==0)
    writeFout(tmp);
  else writeGlobal(tmp);

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

declar_de_variables_locales: INICIOV variables_locales FINV |;
variables_locales:variables_locales cuerpo_decla_variables
	|cuerpo_decla_variables | error;

cuerpo_decla_variables: 
TIPOSIMPLE 
{
  tipoTmp = $1.tipo;
  dec_flag=1;
  if(main_flag==0)
    writeFout(dtipo2ctipostr($1.tipo));
  else
    writeGlobal(dtipo2ctipostr($1.tipo)); 

} 
lista_variables 
{
  dec_flag=0;
  if(main_flag==0)
    writeFout(";\n");
  else
    writeGlobal(";\n");

} PYC;

lista_variables: 
lista_variables COMA
{
  if(dec_flag ){
    if(main_flag==0)
    writeFout(",");
    else
      writeGlobal(",");


  }
} 
iden 
{
  if(dec_flag){
    TS_InsertaVAR(&$4);
  }
  if(read_flag){
    checkScope(&$4,&$4);
    write_scanf(&$4);//
  }
} 
| iden 
{
  if(dec_flag){
  TS_InsertaVAR(&$1);
  }
  if(read_flag){
    checkScope(&$1,&$1);
    write_scanf(&$1);//
  }
} 
| error ;//sincroniza con COMA o PYC

sentencias: sentencias sentencia | sentencia;

sentencia: bloque
           |sentencia_asignacion
	   | sentencia_if
           | sentencia_while
	   | sentencia_entrada
	   | sentencia_salida
| procedimiento {checkProced(&$1,&$$);}
           | sentencia_case | error;

sentencia_asignacion: iden {checkScope(&$1,&$1);writeFout("{//Inicio asignacion\n"); } ASIG expresion {
checkEqualTypeAsig(&$1,&$4);
 if(es_array($1.tipo) && es_array($4.tipo)){
   checkEqualDimenArray(&$1,&$4);
   //showAtt(&$1);
   //showAtt(&$4);
 }
 writeFout($1.lexema); //TODO ARRAYS
 writeFout(" = ");
 writeFout($4.expr_tmp);
 writeFout(";\n}//Fin asignacion\n");

} PYC;

expresion: 
PARIZ expresion PARDER 
{

atributocpy(&$$,&$2);
//getchar
}
| OPB_ADD expresion %prec OPU{
  atributocpy(&$$,&$2);
  /*AnyCheck?*/
  /* si está activo el flag de array dar error para $1.atrib=2 ( - ) */
  if(array_flag){
    checkSignArray(&$1);//TODO
  }
  writeOpuExpr(&$$,$1.lexema,&$2);
  //TODO writeExpr
  //printf("OPU_ADD\n");
  getchar();
} 
| expresion OPB_OR expresion{
  atributocpy(&$$,&$1);
  if(check_OPB_OR(&$1,&$3)==0) $$.tipo=desconocido;
  $$.lexema = "_";
  writeExpr(&$$,&$1,$2.lexema,&$3);
}
| expresion OPB_AND expresion{
 

  atributocpy(&$$,&$1);

  if(check_OPB_AND(&$1,&$3)==0) $$.tipo=desconocido;
  $$.lexema = "_";
 
  writeExpr(&$$,&$1,$2.lexema,&$3);
}
| expresion OPB_IG expresion{
  atributocpy(&$$,&$1);
  if(check_OPB_IG(&$1,&$3)==0)
    $$.tipo=desconocido;
  else
    $$.tipo=booleano;
  $$.lexema = "_";
  writeExpr(&$$,&$1,$2.lexema,&$3);
}
| expresion OPB_REL expresion{
  atributocpy(&$$,&$1);
  if(check_OPB_REL(&$1,&$3)==0)
    $$.tipo=desconocido;
  else{
    $$.tipo=booleano;
  }
  $$.lexema = "_";
 
  writeExpr(&$$,&$1,$2.lexema,&$3);
  
}
| expresion OPB_ADD expresion{
  atributocpy(&$$,&$1);
  if(check_OPB_ADD(&$1,&$3)==0 ||checkEqualDimenArray(&$1,&$3)==0)
    $$.tipo=desconocido;
  $$.lexema = "_";
  
  writeExpr(&$$,&$1,$2.lexema,&$3);
  //  printf("%s = %s OPB_ADD %s\n",$$.expr_tmp,$1.expr_tmp,$3.expr_tmp);
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
  writeExpr(&$$,&$1,$2.lexema,&$3);
}
| OPU expresion 
{ if(checkBoolean(&$2)==0)
    $$.tipo=desconocido; 
  else $$.tipo=$2.tipo;
  //TODO writeExpr
  writeOpuExpr(&$$,$1.lexema,&$2);

}
| iden 
{
 checkScope(&$1,&$$);
 if($$.dimensiones == $1.dimensiones){
   $$.tipo=tipoArray($$.tipo);
 }//else if($$.dimensiones == $1.dimensiones+1){
   //
 //}

 // $$.expr_tmp = strdup($1.lexema); OJO ****
 
}
| CONSTANTE
{
atributocpy(&$$,&$1); 
 if($$.tipo != booleano)
   $$.expr_tmp = strdup($1.lexema);
} 
| CONSTANTE_E
{
atributocpy(&$$,&$1); $$.expr_tmp = strdup($1.lexema);
}
| CARACTER
{
atributocpy(&$$,&$1); $$.expr_tmp = strdup($1.lexema);
}
| agregados{ /*que no sea index de array o se pase a proc*/ }
| error;

procedimiento: IDENTIFICADOR PARIZ 
{call_procedure_flag=1;
  writeFout($1.lexema);
  writeFout("(");
} 
lista_expresiones PARDER 
{
  writeFout(");\n");
call_procedure_flag=0;
 checkCallProc(&$1,&$$);

} PYC
|IDENTIFICADOR PARIZ PARDER 
{
  writeFout($1.lexema);
  writeFout("();");
checkCallProcWithoutArgs(&$1,&$$);

}PYC
;

agregados: INICIO lista_expresiones FINBLO;

lista_expresiones: lista_expresiones COMA expresion 
{if(call_procedure_flag){
    linkAtt(&$3);
    writeFout(",");
    writeFout($3.expr_tmp);
  }
} 
| expresion
{if(call_procedure_flag){
    linkAtt(&$1);
    writeFout($1.expr_tmp);
  }
}
;

sentencia_if: alternativa_doble {write_close_if();}| alternativa_simple{write_close_if();};

alternativa_simple: if_expresion_sentencia {writeFout("} //Fin Sentencia IF\n");};

alternativa_doble: if_expresion_sentencia ELSE sentencia {writeFout("} //Fin Sentencia IF-ELSE\n");};

if_expresion_sentencia: 
{writeFout("{ //Sentencia IF\n");}
IF expresion 
{
  write_init_if();
  write_conditional_jump_to_else_tag(&$3);
checkBoolean(&$3);
} 
sentencia
{
write_go_to_exit_tag();
write_else_tag();
}
;

sentencia_while: WHILE PARIZ 
{ 
write_init_while();
 write_entry_tag();
} 
expresion 
{
  write_conditional_jump_to_exit(&$4);
checkBoolean(&$4);
} 
PARDER sentencia
{
  write_go_to_entry_tag();
  write_close_while();
}
;

sentencia_entrada: READ {read_flag = 1;} lista_variables {read_flag = 0;} PYC;

sentencia_salida: WRITE lista_expresiones_o_cadena PYC;

lista_expresiones_o_cadena: lista_expresiones_o_cadena COMA expresion_o_cadena | expresion_o_cadena;

expresion_o_cadena: expresion {checkScope(&$1,&$1);write_printf(&$1);} | CADENA {write_printf_str(&$1);};

sentencia_case: 
SWITCH PARIZ iden 
{
checkScope(&$3,&$3);
checkIntOrChar(&$3);
write_init_switch(&$3);
} 
PARDER INICIO casos caso_por_defecto FINBLO {write_exit_switch();};

casos: 
casos CASE opcion DOSP 
{
  write_init_case();
  write_compare_case(&$3);
} 
sentencias 
{
  write_go_to_exit_switch();
  write_exit_case_tag();
  write_close_case();

}
BREAK PYC | ;

opcion: CONSTANTE_E | CARACTER;

caso_por_defecto: DEFAULT DOSP sentencias {/* popTSIC();*/} | ;


%%

#include "lex.yy.c"


void yyerror( const char *msg )
{
	printf("\nLinea %d: ERROR-> %s\n", yylineno, msg);
	

}
