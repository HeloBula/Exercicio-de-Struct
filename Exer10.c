#include <stdio.h>
#include <string.h>
#define n 10
int main(void) {
  typedef struct{
    char nome[100];
    char sexo;
    float peso;
    float altura;
    char cpf[12];
  }paciente;
  paciente p[n];
  char cpfcomp[12];
  int k = 1, j=0;
  float IMC;
//Preenchendo
  for(int i=0;i<n;i++)
    {
      printf("Escreva seu nome: ");
      scanf(" %[^\n]s",p[i].nome);
      printf("Sexo(F ou M): ");
      scanf(" %c",&p[i].sexo);
      printf("Insira seu peso em Kg: ");
      scanf(" %f",&p[i].peso);
      printf("Insira sua altura: ");
      scanf(" %f",&p[i].altura);
      printf("Digite seu CPF: ");
      scanf(" %s",p[i].cpf);
      printf("\n");
    }
  //cpf para comparação
  printf("Informe o CPF: ");
  scanf("%s",cpfcomp);
  //VER E ACHAR O CPF NA LISTA
  do{
  k = strcmp(cpfcomp,p[j].cpf);
  j++;
    }while(k != 0);
    
  //Depois de achar
   IMC= p[j-1].peso/(p[j-1].altura*p[j-1].altura); 
  printf("O IMC da pessoa com esse CPF é: %.2f",IMC);

  
  return 0;
}