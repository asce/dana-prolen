
#include "tablaSimbolos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char fileOutName[256];
FILE* fileOut;
unsigned int tmp_index=0;
unsigned int tag_index=0;

char* last_tmp;
char* actual_tmp;
char expresion_str[256];
char* tmp;
char* tag;
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
char* name_control_var;
}control_descriptor_t;

void itostr(int i,char* str){
  sprintf(str,"%i",i);
}

void openFiles(char * fileOutName){

  fileOut = fopen(fileOutName,"w");
  fprintf(fileOut,"%s","#include <stdio.h>\n#include <stdlib.h>\n\n");
}

void closeFiles(){

  fclose(fileOut);

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
  tag_index++;
  //return tag_str;
}

void writeExpr(atributos* dest,atributos* op1,char* operador,atributos* op2){
  char tmp[20];
  tmp[0]='\0';
  generateTmp(tmp);
  dest->expr_tmp = strdup(tmp);
  //  printf("%s %s",dtipo2ctipostr(dest->tipo), dest->expr_tmp);
  //getchar();
  sprintf(expresion_str,"%s %s;\n%s = %s %s %s;\n",
	  dtipo2ctipostr(dest->tipo), dest->expr_tmp, dest->expr_tmp, op1->expr_tmp,
	  operador, op2->expr_tmp);
  //printf("%s",expresion_str);
  //getchar();
  writeFout(expresion_str);

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
  printf("%s",expresion_str);
  getchar();
  writeFout(expresion_str);

}

void write_close_if(){
  writeFout("exit_tag:;\n");
    //Limpia TS;

}

void write_init_if(){

  char exit_tag[20], else_tag[20], ite_str[256];
  exit_tag[0]='\0';
  else_tag[0]='\0';
  ite_str[256]='\0';
  //1 generar etiqueta salida y else
  generateTmp(exit_tag);
  generateTmp(else_tag);
  control_descriptor_t cd;

  cd.exit_tag = exit_tag;
  cd.else_tag = else_tag;
  // 2 TODO push cd
  writeFout("//generamos tags y los introducimos en TS\n");

}

void write_go_to_exit_tag(){

  writeFout("goto exit_tag;\n");


}


void write_conditional_jump_to_else_tag(atributos* expr){
  char  ite_str[256];
  ite_str[0]='\0';
  // 4 Se emite la sentencia de salto condicional hacia el else
  sprintf(ite_str,"if(!%s) goto %s;\n",expr->expr_tmp,"else_tag");// TODO OJO ANIDAMIENTO
  writeFout(ite_str);

}

void write_conditional_jump_to_exit(atributos* expr){
  char ite_str[256];
  ite_str[0]='\0';
  // 4 Se emite la sentencia de salto condicional hacia salida        
  sprintf(ite_str,"if(!%s) goto %s;\n",expr->expr_tmp,"exit_tag");// TODO OJO ANIDAMIENTO
  writeFout(ite_str);

}

void write_else_tag(){
  
  writeFout("else_tag:;\n");

}
void write_exit_tag(){

  writeFout("exit_tag:;\n");

}
