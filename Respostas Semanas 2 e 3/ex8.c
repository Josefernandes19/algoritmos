#include <stdio.h>
#include <stdlib.h>

/*Receba dois vetores de 10 posições, e coloque a soma
deles (no mesmo campo i) em um terceiro vetor.*/

int main(int argc, char const *argv[]) {
int A[10];
int B[10];
int C[10];
int i=0;
while(i<10){
  printf("Valor %d do vetor A: ", i);
  scanf("%d", &A[i]);
  i++;
}
i=0;
while(i<10){
  printf("Valor %d do vetor B: ", i);
  scanf("%d", &B[i]);
  i++;
}
i=0;
printf("-----------\n");
  while(i<10){
    C[i]=A[i]+B[i];
    printf("Soma dos vetores na posição %d: %d\n", i, C[i]);
    i++;
  }
  return 0;
}
