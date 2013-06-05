#include <stdio.h>
#include <stdlib.h>

int m , j , a , b , c , fd ;
 int h , d ;
 int main(){
 {//Inicio asignacion
 a  =  1 ;
}//Fin asignacion
 //generar tag salida
 // Almacenar entrada en TS con el valor de expr (Entero o char)
 //generar exit_case_tag 
 //insertar exit_case_tag en TS 
 int tmp0;
tmp0 = 1 == a;
 if(!tmp0) goto tag1;
 printf("%s","Vale 1\n");
 //generar tag salida
 // Almacenar entrada en TS con el valor de expr (Entero o char)
 //generar exit_case_tag 
 //insertar exit_case_tag en TS 
 int tmp1;
tmp1 = 1 == a;
 if(!tmp1) goto tag3;
 printf("%s","Vale 1\n");
 goto tag2;
 tag3:;
 //Limpiamos TS hasta descriptor de bloque
 //generar exit_case_tag 
 //insertar exit_case_tag en TS 
 int tmp2;
tmp2 = 2 == a;
 if(!tmp2) goto tag4;
 printf("%s","Vale 2\n");
 goto tag2;
 tag4:;
 //Limpiamos TS hasta descriptor de bloque
 printf("%s","Vale default\n");
 tag2:;
 goto tag0;
 tag1:;
 //Limpiamos TS hasta descriptor de bloque
 //generar exit_case_tag 
 //insertar exit_case_tag en TS 
 int tmp3;
tmp3 = 2 == a;
 if(!tmp3) goto tag5;
 printf("%s","Vale 2\n");
 goto tag0;
 tag5:;
 //Limpiamos TS hasta descriptor de bloque
 printf("%s","Vale default\n");
 tag0:;
 
}
 