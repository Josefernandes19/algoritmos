#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  float A[10];
  float nmedia = 0;
  int qmedia=0;
  int i = 0;
  while (i<10) {
    printf("Digite a nota do Aluno: ");
    scanf("%f",&A[i]);
    i = i + 1;
  }
  i=0;
  while (i<10) {
    nmedia = nmedia + A[i];
    i=i+1;
  }
  nmedia = nmedia/10;
  i=0;
  printf("A média é: %f\n", nmedia);
  while (i<10) {
    if(A[i] >= nmedia){
      qmedia = qmedia+1;
      i=i+1;
    }else{
      i=i+1;
    }
  }
  printf("%d Alunos atingiram a média\n", qmedia);
  return 0;
}
