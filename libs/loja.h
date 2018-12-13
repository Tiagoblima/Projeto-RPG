#ifndef LOJA_H
#define LOJA_H
#include <cadastro.h>
#include <status.h>
#include <tagsmenu.h>
//#include <menunav.h>


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
		float poderAtaque, poderDefesa;
		float mana_base = (*user).heroi[cur_heroi].mana_base;
		float vida_base = (*user).heroi[cur_heroi].vida_base;
		poderesAdquiridos(&poderAtaque,&poderDefesa,mana_base,vida_base,req_floor[selec]);
		(*user).heroi[cur_heroi].kit[selec] +=1;
		(*user).heroi[cur_heroi].moeda -= req_coins[selec];
		
		user->heroi[cur_heroi].ataque += poderAtaque;
		user->heroi[cur_heroi].defesa += poderDefesa;

		return 1;	
	}
	
}

void adicionarConsumiveis(Cadastro* user,int cur_heroi)
{
	system("cls");
	char cons[4][60]; 
	int opcao,qtd;
	tagsConsumeveis(cons);
	typeLayout(cons,&opcao,3);
	printf("\n\nConsumivel: %s",cons[opcao]);
	do
	{
		printf("\n\nQuantidade :");
		scanf("%i",&qtd);
		if(qtd<=0)
		{
			printf("\nValor inválido!\n");
		}
	}while(qtd<=0);

	switch(opcao)
	{
		case 1: (*user).heroi[cur_heroi].set.hp += qtd;printf("\nAdicionado com sucesso!\n");break;
		case 2:	(*user).heroi[cur_heroi].set.mana +=qtd;printf("\nAdicionado com sucesso!\n");break;
		case 3: (*user).heroi[cur_heroi].set.debuff +=qtd;printf("\nAdicionado com sucesso!\n");break;
		default: printf("Opcao invalida!\n");system("pause");adicionarConsumiveis(user,cur_heroi);
	}
	system("pause");
	
}

void imprimirPreComp(int selec,float mana_base,float vida_base)
{
	system("cls");
	char Equipamento[9][60];
	int req_floor[10],req_coins[10],j;
	printf("\n---------Pre-requisito:--------\n\n");
	
	tagsEquipamentos(Equipamento);
	printf("Equipamento: %s\n\n",Equipamento[selec]);
	for(j=0;j<20;j++)
	{
		printf("-");
	}
	preencherRequisitoCompra(&req_floor[0],&req_coins[0]);
	printf("\n Andar: %i\t Moedas: %i\n\n",req_floor[selec],req_coins[selec]);
	float poderAtaque, poderDefesa;
	poderesAdquiridos(&poderAtaque,&poderDefesa,mana_base,vida_base,req_floor[selec]);
	printf(" Poderes adquiridos: \n");
	printf("\n Ataque: +%.2f\t Defesa: +%.2f\n\n",poderAtaque,poderDefesa);
	
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
	char Equipamentos[9][60];
	tagsEquipamentos(Equipamentos);
	
		
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
	char cons[4][60]; 
	tagsConsumeveis(cons);
	typeLayout(cons,&opcao,3);
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
			else
			{
				//adicionar onde?
				(*user).heroi[cur_heroi].set.debuff--;
				printf("\nAdicionado com sucesso!\n");
			}
			
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
	

		
	int escolha;
	char tags[4][60];
	tagsLojaMenu(tags);
	typeLayout(tags,&escolha,3);
	char Equipamentos [9][60];
	switch(escolha)
	{
		case 1:
		{
			tagsEquipamentos(Equipamentos);
			
			typeLayout(Equipamentos,&selec,8);
			float poderAtaque, poderDefesa;
			float mana_base = (*user).heroi[cur_heroi].mana_base;
			float vida_base = (*user).heroi[cur_heroi].vida_base;
			imprimirPreComp(selec, mana_base,vida_base);
			printf("\n\n1.Comprar");
			printf("\t2.Voltar a loja\n");
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
		case 2:
		{
			adicionarConsumiveis(user,cur_heroi);
			getch();
			loja(user,cur_heroi);
		}break;
		case 3:return 0;break;
		default:printf("Opção inválida!\n");getch();break;
	}

}
#endif

