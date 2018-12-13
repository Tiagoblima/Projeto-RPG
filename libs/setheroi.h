#ifndef SETHEROI_H
#define SETHEROI_H
#include <cadastro.h>
#include <status.h>
#include <menunav.h>

///Funções cadastro do heroi////
//++++++++Módulo de SubClasses em desenvolvimento+++++
void atribuirStatusSubClass(Cadastro* user,int p_newHeroi,int subclasse)
{

	switch((*user).heroi[p_newHeroi].classe)
	{
    case 1:
    	
    	switch(subclasse)
    	{
    		case 1:
    		{
    			user->heroi[p_newHeroi].subclasse[subclasse].vida_base = 100;
        		user->heroi[p_newHeroi].subclasse[subclasse].ataque_base = 50;
       			user->heroi[p_newHeroi].subclasse[subclasse].defesa_base= 50;
        		user->heroi[p_newHeroi].subclasse[subclasse].mana_base= 50;
			}break;
			case 2:
			{
				user->heroi[p_newHeroi].subclasse[subclasse].vida_base = 100;
        		user->heroi[p_newHeroi].subclasse[subclasse].ataque_base = 50;
        		user->heroi[p_newHeroi].subclasse[subclasse].defesa_base= 50;
        		user->heroi[p_newHeroi].subclasse[subclasse].mana_base= 50;	
			}break;
		}break;

    case 2:
    	
    	switch(subclasse)
    	{
    		case 1:
    		{
    			user->heroi[p_newHeroi].subclasse[subclasse].vida_base = 100;
        		user->heroi[p_newHeroi].subclasse[subclasse].ataque_base = 50;
       			user->heroi[p_newHeroi].subclasse[subclasse].defesa_base= 50;
        		user->heroi[p_newHeroi].subclasse[subclasse].mana_base= 50;
			}break;
			case 2:
			{
				user->heroi[p_newHeroi].subclasse[subclasse].vida_base = 100;
        		user->heroi[p_newHeroi].subclasse[subclasse].ataque_base = 50;
        		user->heroi[p_newHeroi].subclasse[subclasse].defesa_base= 50;
        		user->heroi[p_newHeroi].subclasse[subclasse].mana_base= 50;	
			}break;
		}break;
    case 3:
    	
    	switch(subclasse)
    	{
    		case 1:
    		{
    			user->heroi[p_newHeroi].subclasse[subclasse].vida_base = 100;
        		user->heroi[p_newHeroi].subclasse[subclasse].ataque_base = 50;
       			user->heroi[p_newHeroi].subclasse[subclasse].defesa_base= 50;
        		user->heroi[p_newHeroi].subclasse[subclasse].mana_base= 50;
			}break;
			case 2:
			{
				user->heroi[p_newHeroi].subclasse[subclasse].vida_base = 100;
        		user->heroi[p_newHeroi].subclasse[subclasse].ataque_base = 50;
        		user->heroi[p_newHeroi].subclasse[subclasse].defesa_base= 50;
        		user->heroi[p_newHeroi].subclasse[subclasse].mana_base= 50;	
			}break;
		}break;
    case 4:
    {
			
    	switch(subclasse)
    	{
    		case 1:
    		{
    			user->heroi[p_newHeroi].subclasse[subclasse].vida_base = 100;
        		user->heroi[p_newHeroi].subclasse[subclasse].ataque_base = 50;
       			user->heroi[p_newHeroi].subclasse[subclasse].defesa_base= 50;
        		user->heroi[p_newHeroi].subclasse[subclasse].mana_base= 50;
			}break;
			case 2:
			{
				user->heroi[p_newHeroi].subclasse[subclasse].vida_base = 100;
        		user->heroi[p_newHeroi].subclasse[subclasse].ataque_base = 50;
        		user->heroi[p_newHeroi].subclasse[subclasse].defesa_base= 50;
        		user->heroi[p_newHeroi].subclasse[subclasse].mana_base= 50;	
			}break;
		}
		
	}break;
	}
}

int selecionarSubClass(Cadastro* user,int heroi)
{
	//setlocale(LC_ALL,"");
	system("cls");
	int opcao,subclasse;
	char subclasses[3][60];

	do
	{
		
		do
		{
			tagsSubClass(subclasses,(*user).heroi[heroi].classe);
		
			typeLayout(subclasses,&subclasse,2);
						
			printf("\n");
			if(user->heroi[heroi].subclasse[subclasse].on)
			{
				printf("Subclasse ja adicionada\n\n");
				return 0;	
			}		
		}while(user->heroi[heroi].subclasse[subclasse].on);
		
		atribuirStatusSubClass(user,heroi,subclasse);
		imprimirStatusSubClass(*user,heroi,(*user).heroi[heroi].classe,subclasse);
		
		do
		{
			printf("1.Confirma Subclasse\t\t2.Alterar subclasse desejada\n");
	  		printf("\nResposta: ");
	  		scanf("%i",&opcao);
	  		
	  		if(opcao != 1 && opcao != 2)
	  		{
	  			printf("Opção inválida!\n");	
			}	
		}while(opcao != 1 && opcao != 2);
				
		
	
		user->heroi[heroi].subclasse[subclasse].on = 1;

	}while(opcao==2);
	return 1;
}
///////////////////Em desenvolvimento/////////////////
void atribuirStatusClass(Cadastro* user,int p_newHeroi)
{

	switch((*user).heroi[p_newHeroi].classe)
	{
    case 1:
    	(*user).heroi[p_newHeroi].ataque_base=15;
    	(*user).heroi[p_newHeroi].defesa_base=15;
    	(*user).heroi[p_newHeroi].vida_base=20;
    	(*user).heroi[p_newHeroi].mana_base=10;
		
    	break;

    case 2:
    	(*user).heroi[p_newHeroi].ataque_base=6;
    	(*user).heroi[p_newHeroi].defesa_base=4;
    	(*user).heroi[p_newHeroi].vida_base=15;
    	(*user).heroi[p_newHeroi].mana_base=25;

	
    	break;

    case 3:
    	(*user).heroi[p_newHeroi].ataque_base=12;
    	(*user).heroi[p_newHeroi].defesa_base=3;
    	(*user).heroi[p_newHeroi].vida_base=20;
    	(*user).heroi[p_newHeroi].mana_base=15;
		

    	break;

    case 4:
    	(*user).heroi[p_newHeroi].ataque_base=5;
    	(*user).heroi[p_newHeroi].defesa_base=10;
    	(*user).heroi[p_newHeroi].vida_base=25;
    	(*user).heroi[p_newHeroi].mana_base=10;

    	break;
	}
	
	//Setar os consumiveis!
	
}
void atribuirStatus(Cadastro *user, int p_newHeroi)
{
	int i;
	for(i=0;i<10;i++)
	{
		user->heroi[p_newHeroi].kit[i] = 0;	
	}
	for(i=1;i<3;i++)
	{
		user->heroi[p_newHeroi].subclasse[i].on = 0;
	}
	user->heroi[p_newHeroi].andar = 1;
	user->heroi[p_newHeroi].moeda = 0;
	user->heroi[p_newHeroi].set.hp = 0;
	user->heroi[p_newHeroi].set.mana = 0;
	user->heroi[p_newHeroi].set.debuff = 0;
	user->heroi[p_newHeroi].vitoria_seguida = 0;
	user->heroi[p_newHeroi].tot_vitoria = 0;
	user->heroi[p_newHeroi].derrota = 0;
	user->heroi[p_newHeroi].ataque = 0;
	user->heroi[p_newHeroi].defesa = 0;
}
void selecionarClass(Cadastro* user)
{
//	setlocale(LC_ALL,"");
	system("cls");
	int opcao;
	
	char classes[5][60];
	int p_newHeroi = (*user).qtd_herois;
	do
	{
		
		tagsClasses(classes);
	
		
		typeLayout(classes,&(*user).heroi[p_newHeroi].classe,4);
			
		
		printf("\n");
			
		atribuirStatusClass(user,(*user).qtd_herois);
		imprimirStatusClass(*user,(*user).qtd_herois,(*user).heroi[p_newHeroi].classe);
		
		printf("1.Confirma classe\t\t2.Alterar classe desejada\n");
  		printf("\nResposta: ");
  		scanf("%i",&opcao);
	  		
	  	
			
	}while((*user).heroi[p_newHeroi].classe<0 || (*user).heroi[p_newHeroi].classe>4 || opcao==2);
	
}

int verificarDispHeroi(int code,Cadastro user)
{

	int qtd_herois = user.qtd_herois;
	int i;
	for(i=0;i<qtd_herois;i++)
	{
		if(user.heroi[i].code==code)
		{
			return 0;	
		}
	}
	
	if(qtd_herois==10)
	{
		return 0;
	}
	return 1;
}
void solicitarNomeHeroi(Cadastro* user)
{
	system("cls");
	int p_newHeroi = (*user).qtd_herois;
	char nome[10];		
	printf("\nATENCAO: Limite de 10 caracteres; nao utilize espacos");
	printf("\n\nDigite o nome para o heroi: ");
	scanf("%s",(*user).heroi[p_newHeroi].nome);
}

int cadastroHeroi(Cadastro* user)
{

	solicitarNomeHeroi(user);
	
	int check_code;
	
	int p_newHeroi = (*user).qtd_herois;
	
	if(p_newHeroi>=10)
	{
	//	setlocale(LC_ALL,"");
		printf("Você já atingiu a quantidade máxima de heróis possível\n");
		getch();
		return 0;
	}
	gerarCodigo((*user).heroi[p_newHeroi].nome,&check_code);
	
	if(p_newHeroi>0)
	{
			
		if(verificarDispHeroi(check_code,*user))
		{
			(*user).heroi[p_newHeroi].code = check_code;
		}	
		else
		{
			printf("Voce ja possui um heroi com esse nome,\n");
			printf("ou ja atingiu o numero maximo de herois permitido\n\n");
			system("pause");
			return 0;	
		}	
	}
	else
	{
		(*user).heroi[p_newHeroi].code = check_code;	
	}	

	selecionarClass(user);
	atribuirStatus(user,p_newHeroi);
	(*user).qtd_herois = ++p_newHeroi;

	return 1;
}

int configuracoesHeroi(Cadastro* user,int cur_heroi)
{
	system("cls");
	char opcoes[5][60];

	int escolha;
	tagsConfigMenu(opcoes);
	typeLayout(opcoes,&escolha,4);	
	int andar_atual = user->heroi[cur_heroi].andar;


	
	switch(escolha)
	{
		case 1:
		{
			solicitarNomeHeroi(user);
			getch();
			configuracoesHeroi(user,cur_heroi);
		}break;
		case 2:
		{
			if(andar_atual>=20)
			{
				selecionarSubClass(user,cur_heroi);
				
			}
			else
			{
				printf("\n\nChegue no andar 20 para desbloquear a funcionalidade.");

			}
			getch();
			configuracoesHeroi(user,cur_heroi);	
		}break;
		case 3:
		{
		
			if(andar_atual>=20)
			{
				selecionarClass(user);
			}
			else
			{
				printf("\n\nChegue ao andar 20 para desbloquear a funcionalidade.");
			}
			getch();
			configuracoesHeroi(user,cur_heroi);
		}break;
		case 4:
		{
			return 1;
		}
		default:
		{
			printf("Opção inválida!");	
			getch();
			configuracoesHeroi(user,cur_heroi);
		}break;
		
	}
	
}
#endif
