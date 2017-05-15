#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  float A[10];
  float sm = 0;
  int i = 0;
  while (i<10) {
    printf("Digite o valor: ");
    scanf("%f",&A[i]);
    i = i + 1;
  }
  i=0;
  while (i<10) {
    sm = sm + A[i];
    i=i+1;
  }
  printf("A soma é: %f\n", sm);
  return 0;
}
