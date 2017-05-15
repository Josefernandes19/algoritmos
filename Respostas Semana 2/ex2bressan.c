#include <stdio.h>
#include <stdlib.h>

/* Leia 7 valores em um vetor
e dizer o total de pares. */

int main(int argc, char const *argv[]) {
int A[5];
int B[5];
int C[10];
int i=0;
int j=0;

while (i<5){
  printf("Valor %d do vetor A: ", i+1);
  scanf("%d",&A[i]);
  i++;
}
printf("--------------------\n");
i=0;
while (i<5){
  printf("Valor %d do vetor B: ", i+1);
  scanf("%d",&B[i]);
  i++;
}
i=0;
printf("--------------------\n");
printf("VETOR C\n");
printf("--------------------\n");
while (i<5) {
  C[j]=A[i];
  j=j+2;
  i=i+1;
}
i=0;
j=1;
while (i<5) {
  C[j]=B[i];
  j=j+2;
  i=i+1;
}
i=0;
while (i<10) {
  printf("%d\n", C[i]);
  i++;
}
  return 0;
}
