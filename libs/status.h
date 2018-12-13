#ifndef STATUS_H
#define STATUS_H
#include <cadastro.h>
#include <stdio.h>
#include <tagsmenu.h>
#include <menunav.h>

void imprimirStatusClass(Cadastro user,	int p_Heroi,int h_class)
{
	system("cls");
 	char classe[6][60];
	tagsClasses(classe);
	printf("\nClasse Status:\n");
	printf("\nClasse: %s\n\n",classe[h_class]);
	printf("Ataque Base: %.2f\n",user.heroi[p_Heroi].ataque_base);
	printf("Defesa Base: %.2f\n",user.heroi[p_Heroi].defesa_base);
	printf("Mana Base: %.2f\n",user.heroi[p_Heroi].mana_base);
	printf("Vida Base: %.2f\n\n",user.heroi[p_Heroi].vida_base);
}

void imprimirStatusSubClass(Cadastro user,	int p_Heroi,int classe,int sub_class)
{	
	system("cls");
	
 	char subclasse[9][60];
	tagsSubClass(subclasse,classe);	
	printf("\nSubclasse Status:\n");
	printf("\nSubclasse: %s\n\n",subclasse[sub_class]);	
	printf("Ataque Base: %.2f\n",user.heroi[p_Heroi].subclasse[sub_class].ataque_base);
	printf("Defesa Base: %.2f\n",user.heroi[p_Heroi].subclasse[sub_class].defesa_base);
	printf("Mana Base: %.2f\n",user.heroi[p_Heroi].subclasse[sub_class].mana_base);
	printf("Vida Base: %.2f\n\n",user.heroi[p_Heroi].subclasse[sub_class].vida_base);
}

void imprimirStatusConsumiveis(Cadastro user,int cur_heroi)
{
	system("cls");
	printf("Status Consumiveis disponiveis:\n\n");
	printf("\nConsumivel-----Poder de Uso\n\n");
	printf("HP \t\t%i\n",user.heroi[cur_heroi].set.hp);
	printf("\nMana: \t\t%i\n",user.heroi[cur_heroi].set.mana);
	printf("\nDebuff: \t%i\n",user.heroi[cur_heroi].set.debuff);
}
void imprimirStatusHeroi(Cadastro user,int heroi_p)
{
	system("cls");
	printf("\n\nHeroi Status: \n\n");
	char classes[5][60];
	printf("Nome: %s\t",user.heroi[heroi_p].nome);
	printf("\tVitorias seguidas: %i\n",user.heroi[heroi_p].vitoria_seguida);
	printf("\nMoedas: %i",user.heroi[heroi_p].moeda);
	printf("  ");
	printf("Andar: %i",user.heroi[heroi_p].andar);
	printf("\tTotal de Vitorias: %i\n\n",user.heroi[heroi_p].tot_vitoria);
	tagsClasses(classes);
	int heroi_class = user.heroi[heroi_p].classe;
	printf("Classe: %s\t",classes[heroi_class]);
	printf("\tDerrotas: %i\n\n",user.heroi[heroi_p].derrota);
	printf("Poderes adquiridos:\n\n");
	printf("Poder de Ataque: %.2f\t",user.heroi[heroi_p].ataque);
	printf("Poder de Defesa: %.2f\n\n",user.heroi[heroi_p].defesa);


}
void preencherRequisitoCompra(int* req_floor,int* req_coins)
{
	int i;
	int soma_andar = 0;

	for(i=10;i>1;i--)
	{
		soma_andar += ((50/i)-(soma_andar/i))/2;
		*req_floor = soma_andar;
		*req_coins = soma_andar*(50/i);
		req_floor++;
		req_coins++;
	}

}

void poderesAdquiridos(float* poderAtaque,float* poderDefesa,float mana_base,float vida_base,int req_floor)
{


	*poderAtaque = (req_floor*mana_base)/(mana_base+req_floor);
	*poderAtaque += (req_floor+mana_base)/(mana_base/req_floor);
	if(req_floor==13)
	{
		*poderAtaque += (req_floor/mana_base)+(*poderAtaque-req_floor);

	}

	*poderDefesa = (req_floor*vida_base)/(vida_base+req_floor);

	*poderDefesa += ((vida_base*req_floor)*(vida_base/req_floor))/((vida_base+req_floor)-(vida_base/req_floor));
	if(req_floor>4)
	{
		*poderDefesa += (vida_base/req_floor)*(vida_base+req_floor);
	}
	if(req_floor==13)
	{
		*poderDefesa -=	(req_floor/mana_base)+(*poderAtaque-req_floor);
	}
	if(req_floor==31)
	{
		*poderAtaque = mana_base*(req_floor-mana_base);
		*poderAtaque -= (req_floor*mana_base)/(mana_base+req_floor);
		*poderAtaque -= (req_floor+mana_base)/(mana_base/req_floor);
	}

}
void imprimirEquipamentosHeroi(Cadastro user,int cur_heroi)
{

//	setlocale(LC_ALL,"");
	int i,kit[9];
	int equip_ok = 0;
	char Equipamentos[9][60];
	int req_floor[10],req_coins[10];
	tagsEquipamentos(Equipamentos);
	preencherRequisitoCompra(&req_floor[0],&req_coins[0]);
	for(i=0;i<9;i++)
	{
		kit[i] = user.heroi[cur_heroi].kit[i];
	}
	float PoderAtaque,PoderDefesa;
	Personagem heroi = user.heroi[cur_heroi];

	printf("Quantidade----Equipamento---Poder de Ataque---Poder de Defesa \n\n");
	for(i=1;i<9;i++)
	{
		if(kit[i]>0)
		{
			poderesAdquiridos(&PoderAtaque,&PoderDefesa,heroi.mana_base,heroi.vida_base,req_floor[i]);
			printf("  %i\t\t%s\t\t%.2f\t\t%.2f\n\n",kit[i],Equipamentos[i],PoderAtaque,PoderDefesa);
			equip_ok++;
		}
	}
	if(equip_ok==0)
	{
		printf("Voce ainda nao possui equipamentos disponiveis!\n\n");
	}

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
		printf("\n\nVoce ainda nao possui moedas suficientes.\nou nao atingiu o andar requerido.");
		printf("\n\nSuas moedas: %i\n\n",user.heroi[cur_heroi].moeda);
		printf("\nSeu andar atual: %i",user.heroi[cur_heroi].andar);
		printf("\n\nLute para adquirir o equipamento!\n\n");
	}

}


int gerenciamentoStatusHeroi(Cadastro user,int cur_heroi)
{

	char tags[7][60];
	int escolha;
	tagsStatusMenu(tags);
	typeLayout(tags,&escolha,6);
	//Adcionar status consumiveis

	switch(escolha)
	{
		case 1:
		{
			system("cls");
			printf("\n\nStatus Equipamentos : \n\n");
			imprimirEquipamentosHeroi(user,cur_heroi);
			getch();
			gerenciamentoStatusHeroi(user,cur_heroi);
		}break;
		case 2:
		{
			system("cls");
			imprimirStatusClass(user,cur_heroi,user.heroi[cur_heroi].classe);
			getch();
			gerenciamentoStatusHeroi(user,cur_heroi);
		}break;
		case 3:
		{
		//	system("cls");
			imprimirStatusHeroi(user,cur_heroi);
			getch();
			gerenciamentoStatusHeroi(user,cur_heroi);
		}break;
		case 4:
        {
            int subclasse_on = 0; 
            int i;
			for(i=0;i<3;i++)
			{
				if(user.heroi[cur_heroi].subclasse[i].on==1)
				{
					subclasse_on++;
				}	
			}
			
            if(subclasse_on)
            {
	               
				while(subclasse_on)
				{
					int classe = user.heroi[cur_heroi].classe;
	                imprimirStatusSubClass(user,cur_heroi,classe,subclasse_on);
	                getch();
	                subclasse_on--;
				}
				gerenciamentoStatusHeroi(user,cur_heroi);
            }
            else{
                printf("\n\nVoce ainda nao possui subclasse");
                getch();
                gerenciamentoStatusHeroi(user,cur_heroi);

            }
        }break;
		case 5:
		{
			imprimirStatusConsumiveis(user,cur_heroi);
			getch();
			gerenciamentoStatusHeroi(user,cur_heroi);
		}break;
		case 6:
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
