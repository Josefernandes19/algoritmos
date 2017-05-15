#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int V[7];
  int i=0;
  while (i<7) {
    printf("Digite um valor: ");
    scanf("%d",&V[i]);
    i=i+1;
  }
  i=0;
  while (i<7) {
    if((V[i]%2)==0 ){
      printf("%d é par!\n",V[i]);
      i++;
    }else{
      printf("%d é impar!\n", V[i]);
      i++;
    }
  }
  return 0;
}
