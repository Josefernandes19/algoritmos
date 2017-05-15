#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char V[5];
  char A[5];
  int i=0;
  while (i<5) {
    printf("Digite uma alternativa do gabarito: ");
    scanf(" %c",&V[i]);
    i=i+1;
  }
  i=0;
  while (i<5) {
    printf("Digite uma alternativa do aluno: ");
    scanf(" %c",&A[i]);
    i=i+1;
  }
  i=0;
  while (i<5) {
    if((V[i])==A[i]){
      printf("Resposta %d correta!\n",i+1);
      i++;
    }else{
      printf("Resposta %d incorreta!\n",i+1);
      i++;
    }
  }
  return 0;
}
