#include <stdio.h>

#include <stdlib.h>

#define n 20


int main() {

  int i;

  typedef struct cliente{

    char nome[31], sobrenome[41];

    char sexo;

  }clint_t;
 
 struct conta{
 
   int num;
 
   float saldo, lim_esp;
 
   clint_t clint;
 
   int ano_inicio;

  }conta[n];
 
 int nhomem = 0, nmulher = 0;
 
 float salMedH, salMedM, sal_M = 0, sal_F = 0;
 
 float maiorsal, menorsal, maior_lim;

 int clint_ant;

 int cliente_ant_indice = -1;
 
 int cliente_maior_lim=-1; 

 int aux;
 
 //Inserindo dados

  for (i = 0; i < n; i++)

  {
   
 printf("Primeiro nome do titular: ");

    //fflush(stdin);
 
    scanf(" %[^\n]s", conta[i].clint.nome);

    printf("Sobrenome: ");

    //fflush(stdin);
  
    scanf(" %[^\n]s", conta[i].clint.sobrenome);

    printf("Sexo(F ou M): ");
 
   //fflush(stdin);
 
    scanf(" %c", &conta[i].clint.sexo);
 
    printf("Digite o número da conta: ");
 
   //fflush(stdin);
 
    scanf("%d", &conta[i].num);
  
     printf("Ano do início da conta: ");
  
  //fflush(stdin);

    scanf("%d", &conta[i].ano_inicio);
 
   printf("Saldo disponível: ");
 
   //fflush(stdin); 

    scanf("%f", &conta[i].saldo);
 
   printf("Limite especial: ");
 
   //fflush(stdin);  

    scanf("%f", &conta[i].lim_esp);
  
    printf("\n");
  }
  
//Programa em si
 
 for (int j = 0; j < n; j++) 

  {
    if (conta[j].clint.sexo == 'F') 
	{
 nmulher = nmulher + 1;
 
	   sal_F = sal_F + conta[j].saldo;
 
     }else
 
      {nhomem = nhomem + 1;

        sal_M = sal_M + conta[j].saldo;

       }

 	 }
 
   salMedH = sal_M/nhomem;
  
   salMedM = sal_F/nmulher;
 
 //Maior salário

  maiorsal = 0;
 
  menorsal = 0;

  for (int i = 0; i<n; i++)

  { if (i == 0)
  	{
 maiorsal = conta[i].saldo;
 
	  menorsal = conta[i].saldo; 

    }else if (conta[i].saldo > maiorsal)
 
   	{
 maiorsal = conta[i].saldo;

    }else if (conta[i].saldo < menorsal)
 
	   {
 menorsal = conta[i].saldo;

    	}

  }
  
//Ver cliente mais antigo,ignorando clientes do mesmo ano

  clint_ant = 0;

  for (i = 0; i < n; i++) {

    if (i == 0)
    {

      cliente_ant_indice = i;

      clint_ant = conta[i].ano_inicio;

    }else if (conta[i].ano_inicio < clint_ant) 
	{

      clint_ant = conta[i].ano_inicio;

      cliente_ant_indice = i;
    }
 
 	}
 
 //Comparar os limites especiais
 
 maior_lim = 0;

  for (i = 0; i < n; i++)
 
   {
 if (i == 0)
 
     { cliente_maior_lim = i;

      maior_lim = conta[i].lim_esp;

    }else if (conta[i].lim_esp > maior_lim)

      {maior_lim = conta[i].lim_esp;
 
     cliente_maior_lim = i;
    }
  
	}

//Imprimindo

printf("Saldo médio das mulheres:%.2f\n",salMedM);

 if(nhomem==0)
  {
 
   printf("Não foram cadastrados homem\n");
 
 }else{
 
     printf("Saldo médio dos homens:%.2f\n",salMedH);
 
   }

   printf("Maior saldo:%.2f\n",maiorsal);

   printf("Menor saldo:%.2f\n",menorsal);
   
printf("Cliente mais antigo é: %s\n",conta[cliente_ant_indice].clint.nome);

   printf("Cliente com maior limite:%s\n",conta[cliente_maior_lim].clint.nome);
  
   printf("Clientes com saldo negativo:");

for (i = 0; i < n; i++)
  {
  
  if(conta[i].saldo<0)
 
  {printf("\n%s",conta[i].clint.nome);

  }else
 
   { printf("Nennhum cliente possui saldo negativo");
 
     }
 
   printf("\n");
  
	}

  //Não ordenei,muito trampo
} 