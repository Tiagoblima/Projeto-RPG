#ifndef LOJA_H
#define LOJA_H
#include <cadastro.h>
#include <status.h>
typedef struct{
    float ataque,defesa,vida,mana;
    char nome[30];
    int lv;
}Atributos_parciais;
void preencherRequisitoCompra(int* req_floor,int* req_coins)
{
	int i;
	int soma_andar = 0;
		
	for(i=1;i<10;i++)
	{
		soma_andar += 2;
		*req_floor = soma_andar;
		*req_coins = i*20;
		req_floor++;
		req_coins++;	
	}
	
}
////////////////////////////
int realizarEverificarCompra(Cadastro* user,int selec,int cur_heroi)
{
	int i;
	int kit[9];
	int req_floor[10],req_coins[10];
	
	preencherRequisitoCompra(&req_floor[0],&req_coins[0]);	
		
	if((*user).heroi[cur_heroi].moeda<req_coins[selec] || (*user).heroi[cur_heroi].andar<req_floor[selec])
	{
		return 0;	
	}
	else
	{	
		(*user).heroi[cur_heroi].kit[selec] +=1;	
		(*user).heroi[cur_heroi].moeda -= req_coins[selec];
		return 1;	
	}
	
}
void imprimirConsumiveisLoja(void)
{
	char cons[4][10];
	printf("\n\n");

	preencherConsumeveis(cons);
	int i;
	for(i=1;i<4;i++)
	{
		printf("%i.%s\n",i,cons[i]);
	}	
}
void adicionarConsumiveis(Cadastro* user,int cur_heroi)
{
	setlocale(LC_ALL,"");
	system("cls");
	printf("Bem-Vindo aos consumivéis\n\n");
	imprimirConsumiveisLoja();
	int opcao;
	printf("Selecione uma opção: ");
	scanf("%i",&opcao);
	switch(opcao)
	{
		case 1: (*user).heroi[cur_heroi].set.hp++;printf("\nAdicionado com sucesso!\n");break;
		case 2:	(*user).heroi[cur_heroi].set.mana++;printf("\nAdicionado com sucesso!\n");break;
		case 3: (*user).heroi[cur_heroi].set.debuff++;printf("\nAdicionado com sucesso!\n");break;
		default: printf("Opção inválida!\n");system("pause");adicionarConsumiveis(user,cur_heroi);
	}
	system("pause");
	
}

void imprimirRequisitoComp(int selec)
{
	system("cls");
	char Equipamento[9][10];
	int req_floor[10],req_coins[10],j;
	printf("\n---------Pré-requisito:--------\n\n");
	
	preencherEquipamentos(Equipamento);
	printf("Equipamento: %s\n\n",Equipamento[selec]);
	for(j=0;j<20;j++)
	{
		printf("-");
	}
	preencherRequisitoCompra(&req_floor[0],&req_coins[0]);
	printf("\n Andar: %i\n\n Moedas: %i\n\n",req_floor[selec],req_coins[selec]);
	for(j=0;j<10;j++)
	{
		printf("-");
	}
	printf("\n\n");	
}
void imprimirEquipamentosLoja(void)
{
	system("cls");
	setlocale(LC_ALL,"");
	int i,j;
	char Equipamentos[9][10];
	preencherEquipamentos(Equipamentos);
	
		
	printf("----------Equipamentos--------");
	for(i=1;i<9;i++)
	{
		printf("\n\n");	
		for(j=0;j<30;j++)
		{
			printf("-");
		}
		printf("\n\n");
		printf("%i.%s",i,Equipamentos[i]);
		j = 1 +i;
		if(i==5&&j==6)
		{
			printf("\t");	
		}
		else
		{
			printf("\t\t");		
		}
		
		printf("%i.%s",j,Equipamentos[j]);
		i = j;
	}
}

utilizarConsumiveis(Cadastro* user,int cur_heroi,Atributos_parciais* heroi)
{
	setlocale(LC_ALL,"");
	int opcao;
	imprimirConsumiveisLoja();
	
	printf("\n\nEscolha um consumivel a ser utilizado: ");
	scanf("%i",&opcao);	
	switch(opcao)
	{
		case 1:
		{
			if((*user).heroi[cur_heroi].set.hp<=0)
			{
				printf("\nEste consumivel está vazio adquira na loja\n");
			}
			else
			{
				heroi->vida += (*user).heroi[cur_heroi].set.hp;
				printf("\nUtilizado com sucesso!\n");
				(*user).heroi[cur_heroi].set.hp--;
			}
		
		 } break;
		case 2:
			{
			if((*user).heroi[cur_heroi].set.mana<=0)
			{
				printf("\nEste consumivel está vazio adquira na loja\n");
			}
			else
			{
				heroi->mana += (*user).heroi[cur_heroi].set.mana;
				printf("\nUtilizado com sucesso!\n");
				(*user).heroi[cur_heroi].set.mana--;
			}
			
		 } break;
		case 3: 
		{
			if((*user).heroi[cur_heroi].set.debuff<=0)
			{
				printf("\nEste consumivel está vazio adquira na loja\n");
			}
			//adicionar onde?
			(*user).heroi[cur_heroi].set.debuff--;
			printf("\nAdicionado com sucesso!\n");
		}break;
		default: printf("Opção inválida!\n");system("pause");adicionarConsumiveis(user,cur_heroi);
	}		
}
int loja(Cadastro* user,int cur_heroi)
{
	system("cls");
	FILE* file;
	int selec = 1;
	char opcao;
	
  	int kit[8];
	int i;
	
	printf("\nBem-vindo a loja\n\n");	
		
	
	printf("\n\n1.Adquirir Equipamento");
	printf("\n\n2.Adicionar Consumivéis");
	printf("\n\n3.Voltar ao Menu Principal\n");
	
	printf("\nSelecione uma opção: ");
	
	
	switch(getch())
	{
		case 49:
		{
			imprimirEquipamentosLoja();
			do
			{
				printf("\n\nSelecione um equipamento: ");
				scanf("%i",&selec);	
				if(selec<0||selec>9)
				{
					printf("\nOpção inválida!");	
				}
			}while(selec<0||selec>9);
			
			imprimirRequisitoComp(selec);
			printf("\n\n1.Comprar");
			printf("\t2.Voltar à loja\n");
			printf("Selecione uma opção: ");
			if(getch()==49)
			{
				int retorno_compra = realizarEverificarCompra(user,selec,cur_heroi);
				imprimirStatusCompra(retorno_compra,*user,selec,cur_heroi);	
				getch();
				loja(user,cur_heroi);
			}
			else
			{
				loja(user,cur_heroi);
			}
		
		}break;
		case 50:
		{
			adicionarConsumiveis(user,cur_heroi);
			getch();
			loja(user,cur_heroi);
		}break;
		case 51:return 0;break;
		default:printf("Opção inválida!\n");getch();break;
	}

}
#endif

