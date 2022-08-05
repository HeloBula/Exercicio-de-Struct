#include <stdio.h>
#include <stdlib.h>

int main(){
  typedef struct horamin {
    int horas;
    int minutos;
  } horamin;
  horamin tempo;
  int num;

  // Programa principal
  printf("Escreva um tempo em minutos: ");
  scanf("%d", &num);
  // Conversão
  tempo.horas = num / 60;
  tempo.minutos = num % 60;
  printf("Esse tempo corresponde a %d horas e %d minutos", tempo.horas,
         tempo.minutos);

  return 0;
}