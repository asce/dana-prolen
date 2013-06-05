#include <stdio.h>


#define NELEMS(x)  (sizeof(x) / sizeof(x[0]))

void Suma1DArrayEntero(const int a1[],const int a2[],int res[]);
void Suma1DEntero(const int a[],int valor_a_sumar,int res[]);
void Resta1DArrayEntero(const int a1[], const int a2[], int res[]);
void Resta1DEntero(const int a[], int valor_a_restar, int res[]);
void Producto1DArrayEntero(const int a1[],const int a2[], int res[]);
void Producto1DEntero(const a[],int valor, int res[]);
void Division1DArrayEntero(const int a1[],const int a2[], int res[]);
void Division1DEntero(const a[],int valor, int res[]);
void Multiplicacion2DEntero(int *m1,int f1,int c1,int *m2,int f2, int c2, int *producto);



void Suma1DArrayEntero(const int a1[],const int a2[],int res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tiene menos 1, creo que debido al paso del parámetro
    int size = 1 + NELEMS(a1);
    for(i;i<size;i++){
        res[i] = a1[i] + a2[i];
    }
}

void Suma1DEntero(const int a[],int valor_a_sumar,int res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tiene menos 1, creo que debido al paso del parámetro
    int size = 1 + NELEMS(a);
    for(i;i<size;i++){
        res[i] = a[i] + valor_a_sumar;
    }
}

void Resta1DArrayEntero(const int a1[], const int a2[], int res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tiene menos 1, creo que debido al paso del parámetro
    int size = 1 + NELEMS(a1);
    for(i;i<size;i++){
        res[i] = a1[i] - a2[i];
    }

}
void Resta1DEntero(const int a[], int valor_a_restar, int res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tia1ene menos 1, creo que debido al paso del parámetro
    int size = 1 + NELEMS(a);
    for(i;i<size;i++){
        res[i] = a[i] - valor_a_restar;
    }
}

void Producto1DArrayEntero(const int a1[],const int a2[], int res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tiene menos 1, creo que debido al paso del parámetro
    int size = 1 + NELEMS(a1);
    for(i;i<size;i++){
        res[i] = a1[i] * a2[i];
    }
}

void Producto1DEntero(const a[],int valor, int res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tiene menos 1, creo que debido al paso del parámetro
    int size = 1 + NELEMS(a);
    for(i;i<size;i++){
        res[i] = a[i] * valor;
    }
}

void Division1DArrayEntero(const int a1[],const int a2[], int res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tiene menos 1, creo que debido al paso del parámetro
    int size = 1 + NELEMS(a1);
    for(i;i<size;i++){
        res[i] = a1[i] / a2[i];
    }
}
void Division1DEntero(const a[],int valor, int res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tiene menos 1, creo que debido al paso del parámetro
    int size = 1 + NELEMS(a);
    for(i;i<size;i++){
        res[i] = a[i] / valor;
    }
}

void Multiplicacion2DEntero(int *m1,int f1,int c1,int *m2,int f2, int c2, int *producto){
    //Si las matrices se pueden multiplicar
    if(c1==f2){
        int i=0;
        for(i;i<f1;i++){
            int j=0;
            for(j;j<c2;j++){
                int k=0;
                producto[i*c1+j]=0;
                for(k;k<c1;k++){
                    producto[i*c1+j] += m1[i*c1 +k]*m2[k*c2 + j] ;
                }
            }
        }
    }else{
        printf("Las matrices no se pueden multpilicar.Tamaños incompatibles\n");
    }
}









