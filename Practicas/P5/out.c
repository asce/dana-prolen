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
 int tmp2;
tmp2 = 1 == a;
 if(!tmp2) goto tmp1;
 printf("%s","Vale 1\n");
 goto tmp0;
 tmp1:;
 //Limpiamos TS hasta descriptor de bloque
 //generar exit_case_tag 
 //insertar exit_case_tag en TS 
 int tmp4;
tmp4 = 2 == a;
 if(!tmp4) goto tmp3;
 printf("%s","Vale 2\n");
 goto tmp0;
 tmp3:;
 //Limpiamos TS hasta descriptor de bloque
 printf("%s","Vale default\n");
 tmp0:;
 
}
 