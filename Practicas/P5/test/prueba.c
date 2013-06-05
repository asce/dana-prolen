#include <stdio.h>
#include "estructura_de_datos.h"

#define NELEMS(x)  (sizeof(x) / sizeof(x[0]))

//comprobar si se puede hayar el tamaño verdadero de las matrices además de asegurar que c1==f2
struct matriz_entero {
    int **m;
    int f;
    int c;
};

void ReservaMemoriaEntero(struct matriz_entero *m);
void LiberaMemoriaEntero(struct matriz_entero *m);
void Multiplicar(int *matriz1, int f1,int c1,int *matriz2, int f2, int c2, int *pro);
void suma(const int a[],const int b[], int tam, int c[]);
void mul(struct matriz_entero m1,struct matriz_entero m2);

int main(){

    
    int m1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int m2[3][3]={{2,2,4},{5,6,7},{11,43,32}};
    struct matriz_entero prueba;
    int filas = 3, columnas = 3;
    int res[filas][columnas];
    Multiplicacion2DEntero((int *)(m1),filas,columnas,(int *)(m2),filas,columnas, (int *)(res));
 
    int i=0;
    for (i;i<filas;i++){
        int j=0;
        for(j;j<columnas;j++){
            printf("M[%i][%i]=%i\n",i,j,res[i][j]);
        }
    }
    
    
    
    
    
}

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

void Multiplicar(int *matriz1, int f1,int c1,int *matriz2, int f2, int c2,int *pro ){
    
    if(c1==f2){
        int i=0;
        for(i;i<f1;i++){
            int j=0;
            for(j;j<c2;j++){
                int k=0;
                pro[i*c1 +j]=0;
                for(k;k<c1;k++){
                    pro[i*c1 +j] += matriz1[i*c1 +k]*matriz2[k*c2 + j] ;
                    
                    // m1.m[i][k]*m2.m[k][j]
                    //matriz[i*c1 +j]
                    
                }
            }
        }
    }else{
        printf("Las matrices no se pueden multpilicar.\n");
    }
    

}



void suma(const int a[],const int b[], int tam,int c[]){

    int i=0;
    int size = NELEMS(a);
    //printf("Tamaño  : %i\n",size);
    for(i;i<tam;i++){
        c[i] = a[i] + b[i];
    
    }
}




