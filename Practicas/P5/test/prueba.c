#include <stdio.h>
#include "estructura_de_datos.h"

//#define NELEMS(x)  (sizeof(x) / sizeof(x[0]))

//comprobar si se puede hayar el tamaño verdadero de las matrices además de asegurar que c1==f2
struct matriz_entero {
    int **m;
    int f;
    int c;
};

//void ReservaMemoriaEntero(struct matriz_entero *m);
//void LiberaMemoriaEntero(struct matriz_entero *m);
//void Multiplicar(int *matriz1, int f1,int c1,int *matriz2, int f2, int c2, int *pro);
void Multiplicar(int **matriz1, int f1,int c1);
void suma(const int a[],const int b[], int tam, int c[]);
void mul(struct matriz_entero m1,struct matriz_entero m2);

int main(){

    
    int m1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int m2[3][3]={{2,2,4},{5,6,7},{11,43,32}};
    struct matriz_entero prueba;
    int filas = 3, columnas = 3;
    int res[filas][columnas];
    int tamv1=5;
    int tamv2=5;
    int v1[5]={1,2,3,4,5};
    int v2[5]={5,4,3,2,1};
    int total[5];
    int tamv2d=7;
    int tamv1d=5;
    double v1d[5]={2.222,5.435,6.66,7.11,21.44};
    double v2d[7]={5.66,7.88,1.33,4.55,6.899,9.0000,98.000899};
    double totald[5];
    double m1d[2][2]={{2.34,5.66},{7.8890,0.99007}};
    
   // Multiplicar(m1,filas, columnas);
    
    Imprimir2DReal(m1d,2,2);
    
    
    //Multiplicacion2DEntero((int *)(m1),filas,columnas,(int *)(m2),filas,columnas, (int *)(res));
    //Producto2DEntero(m1,filas,columnas,2,res);
    //Resta2DEntero((int *)(m2),filas,columnas,2,(int *)(res));
/*    Asignacion2DEntero(m2,filas,columnas,res);
  
    int i=0;
    for (i;i<filas;i++){
        int j=0;
        for(j;j<columnas;j++){
            printf("M[%i][%i]=%i\n",i,j,res[i][j]);
        }
    }
*/    
  
    //Division1DEntero(v1,NELEMS(v1),1,total);
/*    Asignacion1DReal(v2d,tamv2d,totald);
    int i=0;
    for(i;i<NELEMS(v2d);i++){
        printf("V[%i]=%f\n",i,totald[i]);
    }
   
  */  
    
}
/*
void ReservaMemoriaEntero(struct matriz_entero *m){
    m->m = malloc(sizeof *m->m * m->f);
    int z=0;
    for(z;z<m->f;z++){
        m->m[z]=malloc(sizeof *m->m[z] * m->c);
    }
}

void LiberaMemoriaEntero(struct matriz_entero *m){
    int x=0;
    for(x;x<m->f;x++){
        free(m->m[x]);
    }
    free(m->m);
}
*/









//void Multiplicar(int **matriz1, int f1,int c1,int **matriz2, int f2, int c2,int **pro ){
void Multiplicar(int **matriz1, int f1,int c1){
    
    
        int i=0;
        for(i;i<f1;i++){
            int j=0;
            for(j;j<c1;j++){
             /*   int k=0;
                pro[i*c1 +j]=0;
                for(k;k<c1;k++){
                    pro[i*c1 +j] += matriz1[i*c1 +k]*matriz2[k*c2 + j] ;
                    
                    // m1.m[i][k]*m2.m[k][j]
                    //matriz[i*c1 +j]
                    
                }
              */
                printf("M[%i][%i]=%i\n",i,j,matriz1[i][j]);
                
                
                
                
                
                
            }
        }
  /*  }else{
        printf("Las matrices no se pueden multpilicar.\n");
    }
    */

}



void suma(const int a[],const int b[], int tam,int c[]){

    int i=0;
    printf("Tamaño  : %i\n",tam);
    for(i;i<tam;i++){
        c[i] = a[i] + b[i];
    
    }
   
}




