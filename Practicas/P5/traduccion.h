
#include "tablaSimbolos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char fileOutName[256];
FILE* fileOut;
//FILE* fileProc;
//FILE* actual;

char  temp[11];
char  temp1[11];
char temp2[11];
unsigned int etiqueta_base =0;
unsigned int temporal_base =0;
unsigned int almacena_temp=0;
int main_llave=0;
int en_fun=0;
char** listaConstantes;
int utilConstantes;

typedef struct{
char EtiquetaEntrada[15];
char EtiquetaSalida[15];
char EtiquetaElse[15];
char NombreVarControl[15];
}DescriptorControl;


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

