#include <stdio.h>
#include <stdlib.h>

/*Dada uma seqüência de 20 números, imprima-os na ordem
inversa à da leitura. Para isso, guarde-os em um vetor.*/

int main(int argc, char const *argv[]) {
  int V[20];
  int i=0;
  while(i<20){
    printf("Valor %d do vetor: ", i+1);
    scanf("%d", &V[i]);
    i++;
  }
  printf("----------------------\n");
  i=19;
  while(i>=0){
    printf("Casa %d do vetor: %d\n", i+1, V[i]);
    i--;
  }
  return 0;
}
