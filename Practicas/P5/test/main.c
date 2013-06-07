#include <stdlib.h>
#include "estructura_de_datos.h"
int main(){

  int Ae33[3][3]={{1,0,0},{0,1,0},{0,0,1}};
  int Ae23[2][3]={{1,1,1},{1,1,1}};
  int Ae32[3][2]={{1,1},{1,1},{1,1}};

  /*
  Ae33[0][0]=;Ae33[0][1]=;Ae33[0][2]=;
  Ae33[1][0]=;Ae33[1][1]=;Ae33[1][2]=;
  Ae33[2][0]=;Ae33[2][1]=;Ae33[2][2]=;
  */
  int tmp21[3][3];
  Multiplicacion2DEntero((int *)Ae32,3,2,(int *)Ae23,2,3,(int *)tmp21);
  int tmp22[3][3];
  Multiplicacion2DEntero((int *)tmp21,3,3,(int *)Ae33,3,3,(int *)tmp22);
  Asignacion2DEntero((int *)tmp22,3,3,(int *)Ae33) ;

  Imprimir2DEntero((int*)Ae33,3,3);

  return 0;





}
