#ifndef STATUS_H
#define STATUS_H

#include <cadastro.h>
#include <stdio.h>
void preencherClasses(char classe[6][10])
{
	system("cls");
	printf("\n\n");
	setlocale(LC_ALL,"");	
	
	strcpy(classe[0],"NULL");
	strcpy(classe[1],"Guerreiro");
	strcpy(classe[2],"Mago");
	strcpy(classe[3],"Lutador");
	strcpy(classe[4],"Assassino");
			
}
void imprimirClasses(char classes[6][10])
{
	int i;
	for(i=1;i<5;i++)
	{
		printf("%i.%s\n",i,classes[i]);	
	}		
}
void imprimirStatusClass(Cadastro user,	int p_Heroi,int h_class)
{	
	system("cls");
	
 	char classe[6][10];
	preencherClasses(classe);	
	printf("\nClasse Status:\n");
	printf("\nClasse: %s\n\n",classe[h_class]);	
	printf("Ataque Base: %.2f\n",user.heroi[p_Heroi].ataque_base);
	printf("Defesa Base: %.2f\n",user.heroi[p_Heroi].defesa_base);
	printf("Mana Base: %.2f\n",user.heroi[p_Heroi].mana_base);
	printf("Vida Base: %.2f\n\n",user.heroi[p_Heroi].vida_base);
}

void preencherSubClass(char subclasse[9][60])
{
	system("cls");
	printf("\n\n");
	setlocale(LC_ALL,"");	
	///Módulo em desenvolvimento
	strcpy(subclasse[0],"NULL");
	strcpy(subclasse[1],"Guerreiro1");
	strcpy(subclasse[2],"Guerreiro2");
	strcpy(subclasse[3],"Mago1      ");
	strcpy(subclasse[4],"Mago2");
	strcpy(subclasse[5],"Lutador1");
	strcpy(subclasse[6],"Lutador2");
	strcpy(subclasse[7],"Assassino1");
	strcpy(subclasse[8],"Assassino2");
			
}
void imprimirSubClass(char subclasses[9][10])
{
	int i;	
	for(i=1;i<9;i++)
	{
		printf("%i.%s\n",i,subclasses[i]);	
	}		
}
void imprimirStatusSubClass(Cadastro user,	int p_Heroi,int h_class)
{	
	system("cls");
	
 	char subclasse[9][60];
	preencherSubClass(subclasse);	
	printf("\nClasse Status:\n");
	printf("\nClasse: %s\n\n",subclasse[h_class]);	
	printf("Ataque Base: %.2f\n",user.heroi[p_Heroi].subclasse.ataque_base);
	printf("Defesa Base: %.2f\n",user.heroi[p_Heroi].subclasse.defesa_base);
	printf("Mana Base: %.2f\n",user.heroi[p_Heroi].subclasse.mana_base);
	printf("Vida Base: %.2f\n\n",user.heroi[p_Heroi].subclasse.vida_base);
}

void preencherEquipamentos(char Equipamentos[9][10])
{
	strcpy(Equipamentos[1],"Bota\0");	
	strcpy(Equipamentos[2],"Calça\0");
	strcpy(Equipamentos[3],"Elmo\0");
	strcpy(Equipamentos[4],"Escudo\0");
	strcpy(Equipamentos[5],"Espada\0");	
	strcpy(Equipamentos[6],"Luva\0");
	strcpy(Equipamentos[7],"Ombro\0");
	strcpy(Equipamentos[8],"Couraça\0");
	
}
void preencherConsumeveis(char cons[4][10])
{
	strcpy(cons[0],"Null");
	strcpy(cons[1],"HP");
	strcpy(cons[2],"MANA");
	strcpy(cons[3],"DEBUFF");
}
void imprimirStatusConsumiveis(Cadastro user,int cur_heroi)
{
	printf("Status Consumiveis disponíveis:\n\n");
	printf("\nConsumivel-----Poder de Uso\n\n");
	printf("HP \t\t%i\n",user.heroi[cur_heroi].set.hp);
	printf("\nMana: \t\t%i\n",user.heroi[cur_heroi].set.mana);
	printf("\nDebuff: \t%i\n",user.heroi[cur_heroi].set.debuff);
}
void imprimirStatusHeroi(Cadastro user,int heroi_p)
{
	system("cls");
	printf("\n\nHerói Status: \n\n");
	
	printf("Nome: %s\n",user.heroi[heroi_p].nome);		
	printf("\nMoedas: %i",user.heroi[heroi_p].moeda);
	printf("\t\t");
	printf("Andar: %i\n\n",user.heroi[heroi_p].andar);	
}
void imprimirEquipamentosHeroi(Cadastro user,int cur_heroi)
{
	
	setlocale(LC_ALL,"");
	int i,kit[9];
	int equip_ok = 0;
	char Equipamentos[9][10];
					
	preencherEquipamentos(Equipamentos);
	
	for(i=0;i<9;i++)
	{
		kit[i] = user.heroi[cur_heroi].kit[i];
	}

	
	printf("Equipamentos: \n\n");
	for(i=1;i<9;i++)
	{		
		if(kit[i]>0)
		{
			printf("%i.%s\t\tPoder de uso: %i\n\n",i,Equipamentos[i],kit[i]);	
			equip_ok++;
		}	
	}
	if(equip_ok==0)
	{
		printf("Você ainda não possui equipamentos disponiveis!\n\n");
	}
	
	imprimirStatusConsumiveis(user,cur_heroi);
}
void imprimirStatusCompra(int statusComp,Cadastro user,int selec,int cur_heroi)
{

	int req_floor[10];
	int req_coins[10];
	
	system("cls");
	printf("\n\n");	
	printf("-----------Status da Compra----------");
	if(statusComp==1)
	{
		printf("\n\nEquipamento selecionado com sucesso!\n\n");
		printf("Moedas restantes: %i\n\n",user.heroi[cur_heroi].moeda);
		printf("Andar atual: %i\n\n",user.heroi[cur_heroi].andar);	
	}
	else
	{
		printf("\n\nVocê ainda não possui moedas suficientes.\nou não atingiu o andar requerido.");
		printf("\n\nSuas moedas: %i\n\n",user.heroi[cur_heroi].moeda);
		printf("\nSeu andar atual: %i",user.heroi[cur_heroi].andar);
		printf("\n\nLute para adquirir o equipamento!\n\n");
	}
	
}
void preencherMenuStatus(char opcoes[4][60])
{
	strcpy(opcoes[0],"Null");
	strcpy(opcoes[1],"Status Equipamentos");
	strcpy(opcoes[2],"Status da Classe");
	strcpy(opcoes[3],"Menu Principal");

}
void imprimirStatusMenu(void)
{
	char edge = '+';
	int i,j,k;
	char opcoes[4][60];
	preencherMenuStatus(opcoes);
	for(i=0;i<4;i++)
	{
	
		if(i==0)
		{
			for(j=0;j<32;j++)
			{
				printf(" %c",edge);
				
				if(j==16)
				{
					printf("Menu Status");
				}
			}
		
			printf("\n");
		}
		else
		{
			j = i + 1;
			printf("\n%c\t%i.%s",edge,i,opcoes[i]);
			if(j<3)
			{
				if(j==4)
				{
					printf("\t\t");
				}
				printf("\t\t%i.%s",j,opcoes[j]);
				
			}
			if(i==9)
			{
				printf("\t\t\t\t\t\t\t");	
			}
			if(j == 2)
			{
				printf("\t%c\t\n",edge);
			}	
			else
			{
				printf("\t\t%c\t\n",edge);
			}
			i = j;
		}
	}
		
}
int gerenciamentoStatusHeroi(Cadastro user,int cur_heroi)
{
	imprimirStatusHeroi(user,cur_heroi);
	imprimirStatusMenu();
	printf("Resposta: ");
	switch(getch())
	{
		case 49:
		{
			system("cls");
			printf("\n\nStatus Equipamentos : \n\n");
			imprimirEquipamentosHeroi(user,cur_heroi);
			getch();
			gerenciamentoStatusHeroi(user,cur_heroi);
		}break;
		case 50:
		{
			system("cls");
			imprimirStatusClass(user,cur_heroi,user.heroi[cur_heroi].classe);
			getch();
			gerenciamentoStatusHeroi(user,cur_heroi);	
		}break;
		case 51:
		{
			return 1;
		}break;
		default:
		{
			printf("Opção inválida!");
			getch();
			gerenciamentoStatusHeroi(user,cur_heroi);	
		}break;
	}			
}
#endif
