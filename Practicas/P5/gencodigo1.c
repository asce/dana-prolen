#include <stdio.h>


int main(int argc, char* argv[]){

  int n,curr;
  printf("Introduce numero : ");
  scanf("%d",&n);
  printf(" %d == ",n);
  curr = 2;
  while(curr <= n){

    int d=n/curr;
    if(d*curr == n){

      printf("* %d ",curr);
      n=n/curr;

    }else
      curr=curr+1;
    printf("\n");
    





  }


}
