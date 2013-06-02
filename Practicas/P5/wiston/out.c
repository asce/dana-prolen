#include "dec_fun"
#include "Stack.h"
#include "dec_dat.h"
#include <stdio.h>

int main(){
int n;
int curr;

{
printf("Introduce un numero: ");
}
{
scanf("%i",&n);
}
{
printf(" ");
printf("%d",n);
printf(" == ");
}
{
curr = 2;

}
{
etiqueta0 :
;
;
int temp0;
temp0 = curr <= n;

if(!temp0)goto etiqueta1;

int d;

int temp0;
temp0 = n / curr;
d = temp0;
{
int temp1;
temp1 = d * curr;
int temp2;
temp2 = temp1 == n;
if(!temp2)goto etiqueta3;

{
printf("* ");
printf("%d",curr);
printf(" ");
}
{
int temp0;
temp0 = n / curr;
n = temp0;

}
goto etiqueta2;

etiqueta3:
;
{
int temp0;
temp0 = curr + 1;
curr = temp0;

}
etiqueta2 :
;
}
goto etiqueta0;
etiqueta1:
;
}
{
printf("\n");
}

return 0;
}
