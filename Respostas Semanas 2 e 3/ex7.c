#include <stdio.h>
#include <stdlib.h>

/*Crie um programa em C que peça 10 números,
armazene eles em um vetor e diga qual elemento é
o maior, qual é o menor e quais seus valores.*/

int main(int argc, char const *argv[]) {
  int V[10];
  int i=0;
  int maior=(-11111);
  int pmaior;
  int menor=99999;
  int pmenor;
  while(i<10){
    printf("Valor: ");
    scanf("%d", &V[i]);
    if((V[i])>maior){
      maior = V[i];
      pmaior = i;
    }
    if (V[i]<menor) {
      menor = V[i];
      pmenor = i;
    }
    i++;
  }
  printf("O maior numero é %d e está na posição %d do vetor.\n", maior, pmaior);
  printf("O menor numero é %d e está na posição %d do vetor.\n", menor, pmenor);
  return 0;
}
