#include <stdio.h>
#include <stdlib.h>

/*Tentando descobrir se um dado era viciado,
um dono de cassino o lançou 18 vezes.
Dados os n resultados dos lançamentos,
determinar o número de ocorrências de cada face.*/

int main(int argc, char const *argv[]){
int D[18];
int vz[6];
int i=0;
while(i<18){
  printf("Lançamento %d do dado: ", i+1);
  scanf("%d", &D[i]);
  i++;
}
i=0;
while(i<6){
  vz[i]=0;
  i++;
}
i=0;
  while(i<18){
  if((D[i])==1){
    vz[0]=(vz[0]+1);
  }else if ((D[i])==2) {
    vz[1]=(vz[1]+1);
  } else if ((D[i])==3) {
    vz[2]=(vz[2]+1);
  }else if ((D[i])==4) {
    vz[3]=(vz[3]+1);
  } else if ((D[i])==5) {
    vz[4]=(vz[4]+1);
  }else if ((D[i])==6) {
    vz[5]=(vz[5]+1);
  }
  i++;
  }
  i=0;
  while(i<6){
    printf("Incidência da face %d: %d\n", i+1, vz[i]);
    i++;
  }
  return 0;
}
