
#include "tablaSimbolos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char fileOutName[256];
FILE* fileOut;
FILE* fileFun;
FILE* fileGlobal;
typedef enum {
  MAIN_FILE,
  FUN_FILE,
} file_enum_t ;


unsigned int actual_file = MAIN_FILE;
unsigned int fun_level = 0;
unsigned int tmp_index=0;
unsigned int tag_index=0;

char* last_tmp;
char* actual_tmp;
char expresion_str[256];
char* tmp;
char* tag;
char expr_params[1024];

///////char* last_tag;

//FILE* fileProc;
//FILE* actual;

//char  temp[11];
//char  temp1[11];
//char temp2[11];
//unsigned int etiqueta_base =0;
//unsigned int temporal_base =0;
//unsigned int almacena_temp=0;
//int main_llave=0;
//int en_fun=0;
//char** listaConstantes;
//int utilConstantes;

typedef struct{
char* entry_tag;
char* exit_tag;
char* else_tag;
 char* exit_switch_tag;
char* name_control_var;
}control_descriptor_t;
#define TSIC_SIZE 255
unsigned int TSIC_TOPE = 0;
control_descriptor_t TSIC[TSIC_SIZE];


void switch_actual_file(){

  
  if(actual_file == MAIN_FILE){
    actual_file = FUN_FILE;
  }else{
    actual_file = MAIN_FILE;    
  }
  FILE* tmp;
  tmp = fileOut; 
  fileOut = fileFun;
  fileFun = tmp;
}

void initTSIC(){
  int i; 
  for(i=0;i<TSIC_SIZE;i++){
    TSIC[i].entry_tag=0;
    TSIC[i].exit_tag=0;
    TSIC[i].else_tag=0;
    TSIC[i].exit_switch_tag=0;
    TSIC[i].name_control_var=0;
  }
}
void pushTSIC(control_descriptor_t* cd){

  TSIC_TOPE++;
  TSIC[TSIC_TOPE].entry_tag = cd->entry_tag;
  TSIC[TSIC_TOPE].exit_tag = cd->exit_tag;
  TSIC[TSIC_TOPE].else_tag = cd->else_tag;
  TSIC[TSIC_TOPE].exit_switch_tag = cd->exit_switch_tag;
  TSIC[TSIC_TOPE].name_control_var = cd->name_control_var;

}
void popTSIC(){
  if(TSIC_TOPE >= 0){
  TSIC[TSIC_TOPE].entry_tag=0;
  TSIC[TSIC_TOPE].exit_tag=0;
  TSIC[TSIC_TOPE].else_tag=0;
  TSIC[TSIC_TOPE].exit_switch_tag=0;
  TSIC[TSIC_TOPE].name_control_var=0;
  TSIC_TOPE--;
  }
  else printf("WARNING: No quedan más elementos en TSIC\n");
}

void itostr(int i,char* str){
  sprintf(str,"%i",i);
}

void openFiles(char * fileOutName){

  fileOut = fopen(fileOutName,"w");
  fprintf(fileOut,"%s","#include <stdio.h>\n#include <stdlib.h>\n#include \"dec_fun\"\n#include \"dec_global\"\n\n");
  fileFun = fopen("dec_fun","w");
  fprintf(fileFun,"%s","#include \"dec_global\"\n#include \"estructura_de_datos.h\"\n\n");
  fileGlobal = fopen("dec_global","w");

}

void closeFiles(){

  fclose(fileOut);
  fclose(fileFun);
  fclose(fileGlobal);

}

writeGlobal(char* str){

  fprintf(fileGlobal,"%s ",str);

}

void writeFout(char* str){

  fprintf(fileOut,"%s ",str);

}


void writeMain(){
  
  writeFout("int main(){\n");

}

void generateTmp(char* tmp){
  //char tmp[25];
  char tmp_index_str[20];
  tmp_index_str[0]='\0';
  itostr(tmp_index,tmp_index_str);
  strcat(tmp,"tmp");  
  strcat(tmp,tmp_index_str);  
  tmp_index++;
  last_tmp = tmp;
  //return tmp;
}

void generateTag(char* tag_str){
  //char tag_str[25];
  char tag_index_str[20];
  tag_index_str[0]='\0';
  itostr(tag_index,tag_index_str);
  strcat(tag_str,"tag");
  strcat(tag_str,tag_index_str);
  //printf("%s",tag_str);
  //getchar();
  tag_index++;
  //return tag_str;
}

void writeExpr(atributos* dest,atributos* op1,char* operador,atributos* op2){
  char tmp[20];
  char expresion_str[256];
  expresion_str[0]='\0';
  tmp[0]='\0';
  generateTmp(tmp);
  dest->expr_tmp = strdup(tmp);
  //  printf("%s %s",dtipo2ctipostr(dest->tipo), dest->expr_tmp);
  //getchar();
  //printf("%s %s %s;\n",dest->expr_tmp,  operador,op1->expr_tmp,);
  //printf("%s\n",operador);getchar();
sprintf(expresion_str,"%s %s;\n%s = %s %s %s;\n",
	  dtipo2ctipostr(dest->tipo), dest->expr_tmp, dest->expr_tmp, op1->expr_tmp,
	  operador, op2->expr_tmp);
  //printf("%s",expresion_str);
  //getchar();
  writeFout(expresion_str);

}
//op1 siempre es array
void writeArrayExpr(atributos* dest,atributos* op1,char* operador,atributos* op2){
  char tmp[20];
  char expresion_str[256];
  int tipo_destino = tipoArray(op1->tipo);
  expresion_str[0]='\0';
  tmp[0]='\0';
  generateTmp(tmp);
  dest->expr_tmp = strdup(tmp);
  char call_proc_str[256];
  sprintf(call_proc_str,"test_proc(%s)",tmp);
  char size_str[50];
  if(dest->dimensiones == 1){
    sprintf(size_str,"[%i]",dest->TamDimen1);

  }else if(dest->dimensiones == 2){

    sprintf(size_str,"[%i][%i]",dest->TamDimen1,dest->TamDimen2);


  }else{

    printf("WARNING: Numero de dimensiones incorrecto en att dest pasado a WriteArrayExpr\n");

  }

  //  printf("%s %s",dtipo2ctipostr(dest->tipo), dest->expr_tmp);
  //getchar();
  //printf("%s %s %s;\n",dest->expr_tmp,  operador,op1->expr_tmp,);
  //printf("%s\n",operador);getchar();
sprintf(expresion_str,"%s %s%s;\n%s;\n",
	dtipo2ctipostr(tipo_destino), dest->expr_tmp,size_str, call_proc_str);
  //printf("%s",expresion_str);
  //getchar();
  writeFout(expresion_str);

}

void writeAsigArray(atributos* dest,atributos* src){
  char* tipo_dest_str;
  char asig_str[255];
  char dimen_str[255];
  char* casting_str;
  if(tipoArray(dest->tipo)==entero){

    tipo_dest_str = "Entero";
    casting_str = "(int *)";

  }else if(tipoArray(dest->tipo)==real){

    tipo_dest_str = "Real";
    casting_str = "(double *)";

  }else{
    printf("WARNING: Tipo de dest desc. en asigArray\n");
    getchar();
  }
  if(dest->dimensiones==1){

    sprintf(dimen_str,"%i",dest->TamDimen1);

  }else{

    sprintf(dimen_str,"%i,%i",dest->TamDimen1,dest->TamDimen2);

  }

  asig_str[0]='\0';
  sprintf(asig_str,"Asignacion%iD%s(%s%s,%s,%s%s)",
	  dest->dimensiones,tipo_dest_str,
	  casting_str,src->expr_tmp,
	  dimen_str,
	  casting_str,dest->lexema);
  writeFout(asig_str);
}

void writeAsigArrayPosition(atributos* dest,atributos* src){
  char* tipo_dest_str;
  char asig_str[255];
  char dimen_str[255];
  char* casting_str;

  if(dest->dimensiones==1){

    sprintf(dimen_str,"[%i]",dest->TamDimen1);

  }else{

    sprintf(dimen_str,"[%i][%i]",dest->TamDimen1,dest->TamDimen2);

  }

  asig_str[0]='\0';
  sprintf(asig_str,"%s%s = %s\n",
	  dest->lexema,dimen_str,
	  src->expr_tmp);

  writeFout(asig_str);
}

void writeOpuExpr(atributos* dest,char* operador,atributos* op1){
  char tmp[20];
  tmp[0]='\0';
  generateTmp(tmp);
  dest->expr_tmp = strdup(tmp);
  //  printf("%s %s",dtipo2ctipostr(dest->tipo), dest->expr_tmp);
  //getchar();
  sprintf(expresion_str,"%s %s;\n%s = %s %s;\n",
	  dtipo2ctipostr(dest->tipo), dest->expr_tmp, dest->expr_tmp,
	  operador, op1->expr_tmp);
  //printf("%s",expresion_str);
  //getchar();
  writeFout(expresion_str);

}

void write_close_if(){
  char str[50];str[0]='\0';
  sprintf(str,"%s:;\n",TSIC[TSIC_TOPE].exit_tag);
  writeFout(str);
  popTSIC(); //Limpia TS;

}

void write_init_if(){

  char exit_tag[20], else_tag[20], ite_str[256];
  exit_tag[0]='\0';
  else_tag[0]='\0';
  ite_str[256]='\0';
  //1 generar etiqueta salida y else
  generateTag(exit_tag);
  generateTag(else_tag);
  control_descriptor_t cd;

  cd.exit_tag = strdup(exit_tag);
  cd.else_tag = strdup(else_tag);
  //printf("%s,%s\n",cd.exit_tag,cd.else_tag);getchar();
  // 2 TODO push cd
  pushTSIC(&cd);
  writeFout("//generamos tags y los introducimos en TS\n");

}

void write_go_to_exit_tag(){
  char str[50];str[0]='\0';
  sprintf(str,"goto %s;\n",TSIC[TSIC_TOPE].exit_tag);
  //printf("%s\n",str);getchar();
  writeFout(str);

}


void write_conditional_jump_to_else_tag(atributos* expr){
  char  ite_str[256];
  ite_str[0]='\0';
  // 4 Se emite la sentencia de salto condicional hacia el else
  sprintf(ite_str,"if(!%s) goto %s;\n",expr->expr_tmp,TSIC[TSIC_TOPE].else_tag);// TODO OJO ANIDAMIENTO
  writeFout(ite_str);

}

void write_conditional_jump_to_exit(atributos* expr){
  char ite_str[256];
  ite_str[0]='\0';
  // 4 Se emite la sentencia de salto condicional hacia salida        
  sprintf(ite_str,"if(!%s) goto %s;\n",expr->expr_tmp,TSIC[TSIC_TOPE].exit_tag);// TODO OJO ANIDAMIENTO
  writeFout(ite_str);

}

void write_else_tag(){
  char str[50];str[0]='\0';
  sprintf(str,"%s:;\n",TSIC[TSIC_TOPE].else_tag);
  writeFout(str);
  //writeFout("else_tag:;\n");

}
void write_exit_tag(){
  char str[50];str[0]='\0';
  sprintf(str,"%s:;\n",TSIC[TSIC_TOPE].exit_tag);
  writeFout(str);
  //writeFout("exit_tag:;\n");

}
void write_exit_switch(){
  char str[50];str[0]='\0';
  sprintf(str,"%s:;\n",TSIC[TSIC_TOPE].exit_switch_tag);
  writeFout(str);
  //  while(TSIC[TSIC_TOPE].exit_switch_tag!=0)
    popTSIC();

  //writeFout("exit_switch_tag:;\n");
}

write_go_to_exit_switch(){
  char str[50];str[0]='\0';
  sprintf(str,"goto %s;\n",TSIC[TSIC_TOPE].exit_switch_tag);
  writeFout(str);

  //writeFout("goto exit_switch_tag;\n");

}

write_exit_case_tag(){
  char str[50];str[0]='\0';
  sprintf(str,"%s:;\n",TSIC[TSIC_TOPE].exit_tag);
  writeFout(str);
  //writeFout("exit_case:;\n");

}

void write_init_while(){

  char exit_tag[20], entry_tag[20], ite_str[256];
  exit_tag[0]='\0';
  entry_tag[0]='\0';
  ite_str[256]='\0';
  //1 generar etiqueta salida y else
  generateTag(exit_tag);
  generateTag(entry_tag);
  control_descriptor_t cd;

  cd.exit_tag = strdup(exit_tag);
  cd.entry_tag = strdup(entry_tag);
  // 2 TODO push cd
  pushTSIC(&cd);
  
  writeFout("//generamos tags y los introducimos en TS\n");

}

void write_init_switch(atributos* att){

  char exit_switch_tag[20], ite_str[256];
  exit_switch_tag[0]='\0';

  ite_str[256]='\0';

  generateTag(exit_switch_tag);
  control_descriptor_t cd;

  cd.exit_switch_tag = strdup(exit_switch_tag);
  

  writeFout("//generar tag salida\n");
  cd.name_control_var = strdup(att->lexema);
  //printf("id:%s\n",cd.name_control_var);getchar();
  //printf("id:%s\n",cd.exit_switch_tag);getchar(); 

  writeFout("// Almacenar entrada en TS con el valor de expr (Entero o char)\n");
  pushTSIC(&cd);
  //getchar();
  //printf("%s\n",TSIC[TSIC_TOPE].name_control_var);getchar();

}

void write_init_case(){
  char exit_tag[20],ite_str[256];
  exit_tag[0]='\0';
  ite_str[256]='\0';
  //1 generar etiqueta salida y else                                                                     
  generateTag(exit_tag);
  control_descriptor_t cd;

  cd.exit_tag = strdup(exit_tag);//exit case
  cd.exit_switch_tag = strdup(TSIC[TSIC_TOPE].exit_switch_tag);
  cd.name_control_var = strdup(TSIC[TSIC_TOPE].name_control_var);
  
  // 2 TODO push cd                                                                                      
  pushTSIC(&cd);

  writeFout("//generar exit_case_tag \n");
  writeFout("//insertar exit_case_tag en TS \n");
}

void write_compare_case(atributos* option){
  int value;
  char tmp_str[20];
  tmp_str[0]='\0';		     
  char tmp_str_asig[256];
  char ite_str[256];
  tmp_str_asig[0]='\0';
  ite_str[0]='\0';

  /*  if(option->tipo == entero){
    value = atoi(option->lexema);


  }else if(option->tipo == caracter){
    value = option->lexema[0];
    printf("DEBUG: cadena: %s, entero %i, caracter: %c\n",option->lexema,value,option->lexema[0]);

  }else printf("WARNING: Se ha pasado atributo con tipo no conocido para write_compare_case\n");
  */
  generateTmp(tmp_str);
  sprintf(tmp_str_asig,"int %s;\n%s = %s == %s;\n",tmp_str,tmp_str,option->lexema,TSIC[TSIC_TOPE].name_control_var);
  writeFout(tmp_str_asig);
  
  sprintf(ite_str,"if(!%s) goto %s;\n",tmp_str,TSIC[TSIC_TOPE].exit_tag);// TODO OJO ANIDAMIENTO                          
  writeFout(ite_str);


}

void write_close_case(){
  popTSIC();
  writeFout("//Limpiamos TS hasta descriptor de bloque\n");

}
void write_entry_tag(){
  char str[50];str[0]='\0';
  sprintf(str,"%s:;\n",TSIC[TSIC_TOPE].entry_tag);
  //printf("%s",str);getchar();
  writeFout(str);
  //writeFout("entry_tag:;\n");

}
void write_go_to_entry_tag(){
  char str[50];str[0]='\0';
  sprintf(str,"goto %s;\n",TSIC[TSIC_TOPE].entry_tag);
  writeFout(str);

  //  writeFout("goto entry_tag;\n");


}
void write_close_while(){
  char str[50];str[0]='\0';
  sprintf(str,"%s:;\n",TSIC[TSIC_TOPE].exit_tag);
  writeFout(str);
  //writeFout("exit_tag:;\n");
  popTSIC();


}

void write_printf_str(atributos* att){
  char str_printf[1024];
  char* str = "printf(\"%s\"";
  str_printf[0] = '\0';
  sprintf(str_printf,"%s,%s);\n",str,att->lexema);
  writeFout(str_printf);

}

void write_printf(atributos* att){
  char str_printf[1024];
  char* format;
  char str[1024];
  str[0]='\0';
  if(att->tipo == entero || att->tipo == booleano)
    format = "%i";
  else if(att->tipo == real)
    format = "%f";
  else if(att->tipo == caracter)
    format = "%c";
  else{
    printf("WARNING Tipo %i en write_printf\n",att->tipo);
    getchar();
    return;
  }

  strcat(str,"printf(\"");
  strcat(str,format);
  strcat(str,"\"");
  str_printf[0] = '\0';
  sprintf(str_printf,"%s,%s);\n",str,att->expr_tmp);
  writeFout(str_printf);

}

write_scanf(atributos* att){

  char str_scanf[1024];
  char* format;
  char str[1024];
  //printf("Linea %i\n",yylineno);
  str[0]='\0';
  if(att->tipo == entero )
    format = "\"%i\",&";
  else if(att->tipo == real)
    format = "\"%f\",&";
  else if(att->tipo == caracter)
    format = "\"%c\",&";
  else{
    printf("Tipo %i\n",att->tipo);
    getchar();
  }
  
  //printf("%i",att->lexema==NULL);getchar();
  strcat(str,"scanf(");
  strcat(str,format);
  strcat(str,att->lexema);
  strcat(str,");\n");
 
  writeFout(str);

}

//op1 y op2 siempre es array
void writeMul(atributos* dest,atributos* op1,char* operador,atributos* op2){

  char tmp[20];
  char expresion_str[256];
  char* tipo_dest_str;
  char* casting_str;
  expresion_str[0]='\0';
  tmp[0]='\0';
  generateTmp(tmp);
  dest->expr_tmp = strdup(tmp);

  if(tipoArray(dest->tipo)==entero){

    tipo_dest_str = "Entero";
    casting_str = "(int *)";

  }else if(tipoArray(dest->tipo)==real){

    tipo_dest_str = "Real";
    casting_str = "(double *)";

  }else{
    printf("WARNING: Tipo de dest desc. en asigArray\n");
    getchar();
  }
  char tam_dest_str[50];
  tam_dest_str[0]='\0';
  sprintf(tam_dest_str,"[%i][%i]",dest->TamDimen1,dest->TamDimen2);
  //*_array(op1,1,op2,dest)
  sprintf(expresion_str,"%s %s%s;\nMultiplicacion2D%s(%s%s,%i,%i,%s%s,%i,%i,%s%s);\n",
	  dtipo2ctipostr(tipoArray(op1->tipo)),dest->expr_tmp,tam_dest_str,
	  tipo_dest_str,
	  casting_str,op1->expr_tmp,
	  op1->TamDimen1,op1->TamDimen2,
	  casting_str,op2->expr_tmp,
	  op2->TamDimen1,op2->TamDimen2,
	  casting_str,dest->expr_tmp);
  writeFout(expresion_str);
  //  void Multiplicacion2DEntero(int *m1,int f1,int c1,int *m2,int f2, int c2, int *producto);


  //

}
/*
//op1 siempre es array                                                                               
void writePro(atributos* dest,atributos* op1,char* operador,atributos* op2){



}*/
//op1 siempre es array                                                                                 
void writeAdd(atributos* dest,atributos* op1,char* operador,atributos* op2){


  if(tipoArray(dest->tipo)==entero){

    tipo_dest_str = "Entero";

  }else if(tipoArray(dest->tipo)==real){

    tipo_dest_str = "Real";

  }else{
    printf("WARNING: Tipo de dest desc. en asigArray\n");
    getchar();
  }



  if(es_array(op2->tipo)){//Ambos arrays

    if(dest->dimensiones==1){




    }else if(dest->dimensiones==2){




    }


  }else{//Array add scalar









  }


}
//op1 siempre es array                                                                                 
void writePro(atributos* dest,atributos* op1,char* operador,atributos* op2){
    char tmp[20];
    char expresion_str[256];
    char *tipo_des_str;
    expresion_str[0]='\0';
    tmp[0]='\0';
    generateTmp(tmp);
    dest->expr_tmp = strdup(tmp);
    
    if(tipoArray(dest->tipo)==entero){
        
        tipo_dest_str = "Entero";
        
    }else if(tipoArray(dest->tipo)==real){
        
        tipo_dest_str = "Real";
        
    }else{
        printf("WARNING: Tipo de dest desc. en asigArray\n");
        getchar();
    }
    
    char tam_dest_str[50];
    tam_dest_str[0]='\0';
    
    //Miramos si el op2 es un array o no, y si es un array debemos comprobar que sea de la misma dimensión 1d o 2d
    int tipo_OP2 = es_array(op2->tipo);//1 si es array
    int d1_o_d2_OP2=0;
    if(tipo_OP2==1){
        
        if((op1->dimensiones==op2->dimensiones) && (op1->dimensiones==1)){//Si los 2 son vectores
            if((op1->TamDimen1==op2->TamDimen1) &&(dest->TamDimen1==op1->TamDimen1)){
                 sprintf(tam_dest_str,"[%i]",dest->TamDimen1);
                sprintf(expresion_str,"%s %s%s;\nProducto1DArray%s(%s,%i,%s,%i,%s);\n",dtipo2ctipostr(tipoArray(op1->tipo)),dest->expr_tmp,tam_dest_str,tipo_des_str,op1->expr_tmp,op1->TamDimen1,op2->expr_tmp,op2->TamDimen1,dest->expr_tmp);
            }else{
                printf("WARNING: Distintos tamaños para realizar el produto de matrices\n");
            }
        }else{
            if((op1->dimensiones==op2->dimensiones) && (op1->dimensiones==2)){//Si los 2 son matrices
                if((op1->TamDimen1==op2->TamDimen1) && (op1->TamDimen2==op2->TamDimen2)&& (dest->TamDimen1==op1->TamDimen1) && (dest->TamDimen2==op1->TamDimen2)){
                    sprintf(tam_dest_str,"[%i][%i]",dest->TamDimen1,dest->TamDimen2);
                    sprintf(expresion_str,"%s %s%s;\nProducto2DArray%s(%s,%i,%i,%s,%i,%i,%s);\n",dtipo2ctipostr(tipoArray(op1->tipo)),dest->expr_tmp,tam_dest_str,tipo_des_str,op1->expr_tmp,op1->TamDimen1,op1->TamDimen2,op2->expr_tmp,op2->TamDimen1,op2->TamDimen2,dest->expr_tmp);
                }else{
                    printf("WARNING: Distintos tamaños para realizar el produto de matrices\n");
                }
            }else{
                printf("WARNING:Vector y matriz. No se pueden multiplicar.\n");
            }
        }
    }else{
    //El segundo operando no es array
        //Debemos comprobar que tanto el destino como el fuente tengan el mismo tamaño y dimensiones
        if((op1->dimensiones==des->dimensiones) && (op1->dimensiones==1)){//si es de dimension 1 (vector)
            if(op1->TamDimen1==dest->TamDimen1){
                sprintf(tam_dest_str,"[%i]",dest->TamDimen1);
                /* Falta el valor, no estoy segura si es op2->expr_tmp  */
                sprintf(expresion_str, "%s %s%s;\nProducto1D%s(%s,%i,%i,%s);\n",dtipo2ctipostr(tipoArray(op1->tipo)),dest->expr_tmp,tam_dest_str,tipo_des_str,op1->expr_tmp,op1->TamDimen1,op2->expr_tmp,dest->expr_tmp);
            }else{
                printf("WARNING:Vector fuente y destino incompatibles. No se pueden multiplicar.\n");
            }
        }else{
        //Si es de dimension 2 (matriz)
            if((op1->dimensiones==des->dimensiones) && (oop1->TamDimen2==dest->TamDimen2)){
                    sprintf(tam_dest_str,"[%i][%i]",dest->TamDimen1,des->TamDimen2);
                    /* Falta el valor, no estoy segura si es op2->expr_tmp  */
                    sprintf(expresion_str,"%s %s%s;\nProducto2D%s(%s,%i,%i,%i,%s);\n",dtipo2ctipostr(tipoArray(op1->tipo)),dest->expr_tmp,tam_dest_str,tipo_des_str,op1->expr_tmp,op1->TamDimen1,op1->TamDimen2,op2->expr_tmp,dest->expr_tmp);
                }else{
                    printf("WARNING:Matriz fuente y destino incompatibles. No se pueden multiplicar.\n");
                }
            }
        
        }
    }
    //Añadimos la cadena de la expresión
    writeFout(expresion_str);
}


