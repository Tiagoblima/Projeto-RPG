#ifndef SETHEROI_H
#define SETHEROI_H
#include <cadastro.h>
#include <status.h>
#include <menuconfig.h>
///Funções cadastro do heroi////
//++++++++Módulo de SubClasses em desenvolvimento+++++
void atribuirStatusSubClass(Cadastro* user,int p_newHeroi)
{

	switch((*user).heroi[p_newHeroi].classe)
	{
    case 1:
    	user->heroi[p_newHeroi].subclasse.vida_base = 100;
        user->heroi[p_newHeroi].subclasse.ataque_base = 50;
        user->heroi[p_newHeroi].subclasse.defesa_base= 50;
        user->heroi[p_newHeroi].subclasse.mana_base= 50;

		
    	break;

    case 2:
    	user->heroi[p_newHeroi].subclasse.vida_base = 100;
        user->heroi[p_newHeroi].subclasse.ataque_base = 50;
        user->heroi[p_newHeroi].subclasse.defesa_base= 50;
        user->heroi[p_newHeroi].subclasse.mana_base= 50;

	
    	break;

    case 3:
    	user->heroi[p_newHeroi].subclasse.vida_base = 100;
        user->heroi[p_newHeroi].subclasse.ataque_base = 50;
        user->heroi[p_newHeroi].subclasse.defesa_base= 50;
        user->heroi[p_newHeroi].subclasse.mana_base= 50;

    	break;

    case 4:
    	user->heroi[p_newHeroi].subclasse.vida_base = 100;
        user->heroi[p_newHeroi].subclasse.ataque_base = 50;
        user->heroi[p_newHeroi].subclasse.defesa_base= 50;
        user->heroi[p_newHeroi].subclasse.mana_base= 50;

    	break;
    case 5:
    	user->heroi[p_newHeroi].subclasse.vida_base = 100;
        user->heroi[p_newHeroi].subclasse.ataque_base = 50;
        user->heroi[p_newHeroi].subclasse.defesa_base= 50;
        user->heroi[p_newHeroi].subclasse.mana_base= 50;

    	break;
    case 6:
    	user->heroi[p_newHeroi].subclasse.vida_base = 100;
        user->heroi[p_newHeroi].subclasse.ataque_base = 50;
        user->heroi[p_newHeroi].subclasse.defesa_base= 50;
        user->heroi[p_newHeroi].subclasse.mana_base= 50;

    	break;
    case 7:
    	user->heroi[p_newHeroi].subclasse.vida_base = 100;
        user->heroi[p_newHeroi].subclasse.ataque_base = 50;
        user->heroi[p_newHeroi].subclasse.defesa_base= 50;
        user->heroi[p_newHeroi].subclasse.mana_base= 50;

    	break;
    case 8:
    	user->heroi[p_newHeroi].subclasse.vida_base = 100;
        user->heroi[p_newHeroi].subclasse.ataque_base = 50;
        user->heroi[p_newHeroi].subclasse.defesa_base= 50;
        user->heroi[p_newHeroi].subclasse.mana_base= 50;

    	break;
    	
	}
	
}

void selecionarSubClass(Cadastro* user,int heroi)
{
	setlocale(LC_ALL,"");
	system("cls");
	int opcao;
	printf("++++++Módulo em desenvolvimento+++++");
	char subclasses[9][60];

	do
	{
		
		preencherSubClass(subclasses);
	
		printMenu("Sub Classes",subclasses,8,'*');
			
		printf("\n\nDefina uma subclasse para seu heroi: \n\n");
	
	
		printf("\nSubclasse desejada: ");
		scanf("%i",&(*user).heroi[heroi].classe);
		
	
			
		if((*user).heroi[heroi].classe<0 || (*user).heroi[heroi].classe>4)
		{
			printf("\nOpção inválida!");
		}
		else
		{
		
			printf("\n");
				
			atribuirStatusSubClass(user,heroi);
			imprimirStatusSubClass(*user,heroi,(*user).heroi[heroi].classe);
			
			printf("1.Confirma Subclasse\t\t2.Alterar subclasse desejada\n");
	  		printf("\nResposta: ");
	  		scanf("%i",&opcao);
	  		
	  		if(opcao != 1 && opcao != 2)
	  		{
	  			printf("Opção inválida!\n");	
			}				
		}
	
			
	}while((*user).heroi[heroi].classe<0 || (*user).heroi[heroi].classe>4 || opcao==2);
	
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
	
	user->heroi[p_newHeroi].andar = 1;
	user->heroi[p_newHeroi].moeda = 0;
	user->heroi[p_newHeroi].set.hp = 0;
	user->heroi[p_newHeroi].set.mana = 0;
	user->heroi[p_newHeroi].set.debuff = 0;

}
void selecionarClass(Cadastro* user)
{
	setlocale(LC_ALL,"");
	system("cls");
	int opcao;
	
	char classes[6][10];
	int p_newHeroi = (*user).qtd_herois;
	do
	{
		
		preencherClasses(classes);
	
		imprimirClasses(classes);
			
		printf("\n\nDefina uma classe para seu heroi: \n\n");
	
	
		printf("\nClasse desejada: ");
		scanf("%i",&(*user).heroi[p_newHeroi].classe);
		
	
			
		if((*user).heroi[p_newHeroi].classe<0 || (*user).heroi[p_newHeroi].classe>4)
		{
			printf("\nOpção inválida!");
		}
		else
		{
		
			printf("\n");
				
			atribuirStatusClass(user,(*user).qtd_herois);
			imprimirStatusClass(*user,(*user).qtd_herois,(*user).heroi[p_newHeroi].classe);
			
			printf("1.Confirma classe\t\t2.Alterar classe desejada\n");
	  		printf("\nResposta: ");
	  		scanf("%i",&opcao);
	  		
	  		if(opcao != 1 && opcao != 2)
	  		{
	  			printf("Opção inválida!\n");	
			}	
			
				
		}
	
			
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
	setlocale(LC_ALL,"");
	int p_newHeroi = (*user).qtd_herois;
	char nome[10];		
	printf("\nATENCÃO: Limite de 10 caracteres; não utilize espaços");
	printf("\n\nDigite o nome para o heroi: ");
	scanf("%s",(*user).heroi[p_newHeroi].nome);
}

int cadastroHeroi(Cadastro* user)
{
	setlocale(LC_ALL,"");
	solicitarNomeHeroi(user);
	
	int check_code;
	
	int p_newHeroi = (*user).qtd_herois;
	
	gerarCodigo((*user).heroi[p_newHeroi].nome,&check_code);
	
	if(p_newHeroi>0)
	{
			
		if(verificarDispHeroi(check_code,*user))
		{
			(*user).heroi[p_newHeroi].code = check_code;
		}	
		else
		{
			printf("Você já possui um herói com esse nome,\n");
			printf("ou já atingiu o número máximo de heróis permitido\n\n");
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

	
	fillLabels("Menu Configurações.txt",opcoes,4);
	printMenu("Configurações",opcoes,4,'-');
//	saveMenu("Menu Configurações.txt",opcoes,4);	
	int andar_atual = user->heroi[cur_heroi].andar;

	printf("\nResposta: ");
	
	switch(getch())
	{
		case 49:
		{
			solicitarNomeHeroi(user);
			getch();
			configuracoesHeroi(user,cur_heroi);
		}break;
		case 50:
		{
			if(andar_atual>20)
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
		case 51:
		{
		
			if(andar_atual>20)
			{
				selecionarClass(user);
			}
			else
			{
				printf("\n\nChegue no andar 20 para desbloquear a funcionalidade.");
			}
			getch();
			configuracoesHeroi(user,cur_heroi);
		}break;
		case 52:
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
