#include <stdio.h>


#define NELEMS(x)  (sizeof(x) / sizeof(x[0]))

//Tener en cuenta que hay que declarar el vector resultado con su tamaño correspondiente
//Cuando a las funciones le entrar punteros, son matrices con casting

void Suma1DArrayEntero(const int a1[],int sizea1,const int a2[],int sizea2,int res[]);
void Suma1DEntero(const int a[],int size,int valor_a_sumar,int res[]);
void Resta1DArrayEntero(const int a1[],int sizea1, const int a2[], int sizea2,int res[]);
void Resta1DEntero(const int a[],int size, int valor_a_restar, int res[]);
void Producto1DArrayEntero(const int a1[],int sizea1,const int a2[], int sizea2,int res[]);
void Producto1DEntero(const int a[],int size,int valor, int res[]);
void Division1DArrayEntero(const int a1[],int sizea1,const int a2[], int sizea2,int res[]);
void Division1DEntero(const int a[],int size,int valor, int res[]);
void Multiplicacion2DEntero(int *m1,int f1,int c1,int *m2,int f2, int c2, int *producto);
void Suma2DArrayEntero(const int *a1,int f1,int c1,const int *a2,int f2,int c2,int *res );
void Suma2DEntero(const int *a,int f ,int c,int valor_a_sumar, int *res);
void Resta2DArrayEntero(const int *a1, int f1, int c1, const int *a2, int f2, int c2, int *res);
void Resta2DEntero(const int *a,int f,int c,int valor_a_restar, int *res);
void Producto2DArrayEntero(const int *a1,int f1,int c1,const int *a2,int f2,int c2,int *res );
void Producto2DEntero(const int *a, int f,int c,int valor, int *res);
void Division2DArrayEntero(const int *a1,int f1,int c1,const int *a2,int f2,int c2,int *res);
void Division2DEntero(const int *a, int f,int c,int valor, int *res);
void Asignacion1DEntero(const int a[], int size, int res[]);
void Asignacion2DEntero(const int *a, int f,int c, int *res);
void Imprimir1DEntero(const int v[], int size);
void Imprimir2DEntero(const int *m, int f, int c);







void Suma1DArrayReal(const double a1[],int sizea1,const double a2[],int sizea2,double res[]);
void Suma1DReal(const double a[],int size,double valor_a_sumar,double res[]);
void Resta1DArrayReal(const double a1[],int sizea1, const double a2[], int sizea2,double res[]);
void Resta1DReal(const double a[],int size, double valor_a_restar, double res[]);
void Producto1DArrayReal(const double a1[],int sizea1,const double a2[], int sizea2,double res[]);
void Producto1DReal(const double a[],int size,double valor, double res[]);
void Division1DArrayReal(const double a1[],int sizea1,const double a2[], int sizea2,double res[]);
void Division1DReal(const double a[],int size,double valor, double res[]);
void Multiplicacion2DReal(double *m1,int f1,int c1,double *m2,int f2, int c2, double *producto);
void Suma2DArrayReal(const double *a1,int f1,int c1,const double *a2,int f2,int c2,double *res );
void Suma2DReal(const double *a,int f ,int c,double valor_a_sumar, double *res);
void Resta2DArrayReal(const double *a1, int f1, int c1, const double *a2, int f2, int c2, double *res);
void Resta2DReal(const double *a,int f,int c,double valor_a_restar, double *res);
void Producto2DArrayReal(const double *a1,int f1,int c1,const double *a2,int f2,int c2,double *res );
void Producto2DReal(const double *a, int f,int c,double valor, double *res);
void Division2DArrayReal(const double *a1,int f1,int c1,const double *a2,int f2,int c2,double *res);
void Division2DReal(const double *a, int f,int c,double valor, double *res);
void Asignacion1DReal(const double a[], int size, double res[]);
void Asignacion2DReal(const double *a, int f,int c, double *res);
void Imprimir1DReal(const double v[], int size);
void Imprimir2DReal(const double *m, int f, int c);





/* __________________________________________________________________________________  */


void Suma1DArrayEntero(const int a1[],int sizea1,const int a2[],int sizea2,int res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tiene menos 1, creo que debido al paso del parámetro
    if(sizea1==sizea2){
        for(i;i<sizea1;i++){
            res[i] = a1[i] + a2[i];
        }
    }else{
        printf("Los vectores no se pueden sumar.Tamaños incompatibles.\n");
    }
}

void Suma1DEntero(const int a[],int size,int valor_a_sumar,int res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tiene menos 1, creo que debido al paso del parámetro
    for(i;i<size;i++){
        res[i] = a[i] + valor_a_sumar;
    }
}

void Resta1DArrayEntero(const int a1[],int sizea1, const int a2[], int sizea2,int res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tiene menos 1, creo que debido al paso del parámetro
    if(sizea1==sizea2){
        for(i;i<sizea1;i++){
            res[i] = a1[i] - a2[i];
        }
    }else{
        printf("Los vectores no se pueden restar.Tamaños incompatibles.\n");
    }

}
void Resta1DEntero(const int a[], int size,int valor_a_restar, int res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tia1ene menos 1, creo que debido al paso del parámetro
    for(i;i<size;i++){
        res[i] = a[i] - valor_a_restar;
    }
}

void Producto1DArrayEntero(const int a1[],int sizea1,const int a2[], int sizea2,int res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tiene menos 1, creo que debido al paso del parámetro
    if(sizea1==sizea2){
        for(i;i<sizea1;i++){
            res[i] = a1[i] * a2[i];
        }
    }else{
        printf("Los vectores no se pueden multiplicar.Tamaños incompatibles.\n");
    }
}

void Producto1DEntero(const a[],int size,int valor, int res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tiene menos 1, creo que debido al paso del parámetro
    for(i;i<size;i++){
        res[i] = a[i] * valor;
    }
}

void Division1DArrayEntero(const int a1[],int sizea1,const int a2[], int sizea2,int res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tiene menos 1, creo que debido al paso del parámetro
    if(sizea1==sizea2){
        for(i;i<sizea1;i++){
            res[i] = a1[i] / a2[i];
        }
    }else{
        printf("Los vectores no se pueden dividir.Tamaños incompatibles.\n");
    }
}
void Division1DEntero(const a[],int size,int valor, int res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tiene menos 1, creo que debido al paso del parámetro
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
        printf("Las matrices no se pueden multiplicar.Tamaños incompatibles\n");
    }
}

void Suma2DArrayEntero(const int *a1,int f1,int c1,const int *a2,int f2,int c2,int *res){
    if ((f1==f2) && (c1==c2)){
        int i=0;
        for(i;i<f1;i++){
            int j=0;
            for(j;j<c1;j++){
                res[i*c1 +j]= a1[i*c1 +j] + a2[i*c1 +j];
            }
        }
    }else{
        printf("Las matrices no se pueden sumar.Tamaños incompatibles.\n");
    }
}

void Suma2DEntero(const int *a,int f ,int c,int valor_a_sumar, int *res){
    int i=0;
    for(i;i<f;i++){
        int j=0;
        for(j;j<c;j++){
            res[i*c +j]= a[i*c +j] + valor_a_sumar;
        }
    }
}

void Resta2DArrayEntero(const int *a1, int f1, int c1, const int *a2, int f2, int c2, int *res){
    if ((f1==f2) && (c1==c2)){
        int i=0;
        for(i;i<f1;i++){
            int j=0;
            for(j;j<c1;j++){
                res[i*c1 +j]= a1[i*c1 +j] - a2[i*c1 +j];
            }
        }
    }else{
        printf("Las matrices no se pueden restar.Tamaños incompatibles.\n");
    }
}

void Resta2DEntero(const int *a,int f ,int c,int valor_a_restar, int *res){
    int i=0;
    for(i;i<f;i++){
        int j=0;
        for(j;j<c;j++){
            res[i*c +j]= a[i*c +j] - valor_a_restar;
        }
    }
}

void Producto2DArrayEntero(const int *a1,int f1,int c1,const int *a2,int f2,int c2,int *res ){
    if ((f1==f2) && (c1==c2)){
        int i=0;
        for(i;i<f1;i++){
            int j=0;
            for(j;j<c1;j++){
                res[i*c1 +j]= a1[i*c1 +j] * a2[i*c1 +j];
            }
        }
    }else{
        printf("Las matrices no se pueden multiplicar.Tamaños incompatibles.\n");
    }
}

void Producto2DEntero(const int *a, int f ,int c,int valor, int *res){
    int i=0;
    for(i;i<f;i++){
        int j=0;
        for(j;j<c;j++){
            res[i*c +j]= a[i*c +j] * valor;
        }
    }
}

void Division2DArrayEntero(const int *a1,int f1,int c1,const int *a2,int f2,int c2,int *res){
    if ((f1==f2) && (c1==c2)){
        int i=0;
        for(i;i<f1;i++){
            int j=0;
            for(j;j<c1;j++){
                res[i*c1 +j]= a1[i*c1 +j] / a2[i*c1 +j];
            }
        }
    }else{
        printf("Las matrices no se pueden dividir.Tamaños incompatibles.\n");
    }
}

void Division2DEntero(const int *a, int f,int c,int valor, int *res){
    int i=0;
    for(i;i<f;i++){
        int j=0;
        for(j;j<c;j++){
            res[i*c +j]= a[i*c +j] / valor;
        }
    }
}

void Asignacion1DEntero(const int a[], int size, int res[]){
    int i=0;
    for(i;i<size;i++){
        res[i]=a[i];
    }
}

void Asignacion2DEntero(const int *a, int f,int c, int *res){
    int i=0;
    for(i;i<f;i++){
        int j=0;
        for(j;j<c;j++){
            res[i*c + j] = a[i*c + j];
        }
    }
}

void Imprimir1DEntero(const int v[], int size){
    int i=0;
    for(i;i<size;i++){
        printf("V[%i]=%i\n",i,v[i]);
    }
}

void Imprimir2DEntero(const int *m, int f, int c){
    int i=0;
    for (i;i<f;i++){
        int j=0;
        for(j;j<c;j++){
            printf("M[%i][%i]=%i\n",i,j,m[i*c+j]);
        }
    }
}

/* __________________________________________________________________________________  */


void Suma1DArrayReal(const double a1[],int sizea1,const double a2[],int sizea2,double res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tiene menos 1, creo que debido al paso del parámetro
    if(sizea1==sizea2){
        for(i;i<sizea1;i++){
            res[i] = a1[i] + a2[i];
        }
    }else{
        printf("Los vectores no se pueden sumar.Tamaños incompatibles.\n");
    }
}

void Suma1DReal(const double a[],int size,double valor_a_sumar,double res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tiene menos 1, creo que debido al paso del parámetro
    for(i;i<size;i++){
        res[i] = a[i] + valor_a_sumar;
    }
}

void Resta1DArrayReal(const double a1[],int sizea1, const double a2[], int sizea2,double res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tiene menos 1, creo que debido al paso del parámetro
    if(sizea1==sizea2){
        for(i;i<sizea1;i++){
            res[i] = a1[i] - a2[i];
        }
    }else{
        printf("Los vectores no se pueden restar.Tamaños incompatibles.\n");
    }

}

void Resta1DReal(const double a[],int size, double valor_a_restar, double res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tia1ene menos 1, creo que debido al paso del parámetro
    for(i;i<size;i++){
        res[i] = a[i] - valor_a_restar;
    }
}

void Producto1DArrayReal(const double a1[],int sizea1,const double a2[], int sizea2,double res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tiene menos 1, creo que debido al paso del parámetro
    if(sizea1==sizea2){
        for(i;i<sizea1;i++){
            res[i] = a1[i] * a2[i];
        }
    }else{
        printf("Los vectores no se pueden multiplicar.Tamaños incompatibles.\n");
    }
}

void Producto1DReal(const double a[],int size,double valor, double res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tiene menos 1, creo que debido al paso del parámetro
    for(i;i<size;i++){
        res[i] = a[i] * valor;
    }
}

void Division1DArrayReal(const double a1[],int sizea1,const double a2[], int sizea2,double res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tiene menos 1, creo que debido al paso del parámetro
    if(sizea1==sizea2){
        for(i;i<sizea1;i++){
            res[i] = a1[i] / a2[i];
        }
    }else{
        printf("Los vectores no se pueden dividir.Tamaños incompatibles.\n");
    }
}

void Division1DReal(const double a[],int size,double valor, double res[]){
    int i=0;
    //Se le suma uno, por que el resultado que da la macro dentro de una función
    //es del tamaño que tiene menos 1, creo que debido al paso del parámetro
    for(i;i<size;i++){
        res[i] = a[i] / valor;
    }
}

void Multiplicacion2DReal(double *m1,int f1,int c1,double *m2,int f2, int c2, double *producto) {
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
        printf("Las matrices no se pueden multiplicar.Tamaños incompatibles\n");
    }
}

void Suma2DArrayReal(const double *a1,int f1,int c1,const double *a2,int f2,int c2,double *res ){
    if ((f1==f2) && (c1==c2)){
        int i=0;
        for(i;i<f1;i++){
            int j=0;
            for(j;j<c1;j++){
                res[i*c1 +j]= a1[i*c1 +j] + a2[i*c1 +j];
            }
        }
    }else{
        printf("Las matrices no se pueden sumar.Tamaños incompatibles.\n");
    }
}

void Suma2DReal(const double *a,int f ,int c,double valor_a_sumar, double *res){
    int i=0;
    for(i;i<f;i++){
        int j=0;
        for(j;j<c;j++){
            res[i*c +j]= a[i*c +j] + valor_a_sumar;
        }
    }
}

void Resta2DArrayReal(const double *a1, int f1, int c1, const double *a2, int f2, int c2, double *res) {
    if ((f1==f2) && (c1==c2)){
        int i=0;
        for(i;i<f1;i++){
            int j=0;
            for(j;j<c1;j++){
                res[i*c1 +j]= a1[i*c1 +j] - a2[i*c1 +j];
            }
        }
    }else{
        printf("Las matrices no se pueden restar.Tamaños incompatibles.\n");
    }
}

void Resta2DReal(const double *a,int f,int c,double valor_a_restar, double *res){
    int i=0;
    for(i;i<f;i++){
        int j=0;
        for(j;j<c;j++){
            res[i*c +j]= a[i*c +j] - valor_a_restar;
        }
    }
}

void Producto2DArrayReal(const double *a1,int f1,int c1,const double *a2,int f2,int c2,double *res ){
    if ((f1==f2) && (c1==c2)){
        int i=0;
        for(i;i<f1;i++){
            int j=0;
            for(j;j<c1;j++){
                res[i*c1 +j]= a1[i*c1 +j] * a2[i*c1 +j];
            }
        }
    }else{
        printf("Las matrices no se pueden multiplicar.Tamaños incompatibles.\n");
    }
}

void Producto2DReal(const double *a, int f,int c,double valor, double *res){
    int i=0;
    for(i;i<f;i++){
        int j=0;
        for(j;j<c;j++){
            res[i*c +j]= a[i*c +j] * valor;
        }
    }
}

void Division2DArrayReal(const double *a1,int f1,int c1,const double *a2,int f2,int c2,double *res){
    if ((f1==f2) && (c1==c2)){
        int i=0;
        for(i;i<f1;i++){
            int j=0;
            for(j;j<c1;j++){
                res[i*c1 +j]= a1[i*c1 +j] / a2[i*c1 +j];
            }
        }
    }else{
        printf("Las matrices no se pueden dividir.Tamaños incompatibles.\n");
    }
}

void Division2DReal(const double *a, int f,int c,double valor, double *res){
    int i=0;
    for(i;i<f;i++){
        int j=0;
        for(j;j<c;j++){
            res[i*c +j]= a[i*c +j] / valor;
        }
    }
}

void Asignacion1DReal(const double a[], int size, double res[]){
    int i=0;
    for(i;i<size;i++){
        res[i]=a[i];
    }
}
void Asignacion2DReal(const double *a, int f,int c, double *res){
    int i=0;
    for(i;i<f;i++){
        int j=0;
        for(j;j<c;j++){
            res[i*c + j] = a[i*c + j];
        }
    }
}

void Imprimir1DReal(const double v[], int size){
    int i=0;
    for(i;i<size;i++){
        printf("V[%i]=%f\n",i,v[i]);
    }
}
void Imprimir2DReal(const double *m, int f, int c){
    int i=0;
    for (i;i<f;i++){
        int j=0;
        for(j;j<c;j++){
            printf("M[%i][%i]=%f\n",i,j,m[i*c+j]);
        }
    }
}




