
#include <game.h>
#include <cadastro.h>
#include <loja.h>
#include <intro.h>
#include <windows.h>
#include <track.h>
#include <setheroi.h>
#include <status.h>
#include <menunav.h>
#include <tagsmenu.h>

int mainMenu(Cadastro* user,int cur_heroi)
{
	
	system("cls");

	char tags[9][60];
	tagsMainMenu(tags);
	int escolha;
	typeLayout(tags,&escolha,7);
	
	switch(escolha)
	{
		case 1:
		{
			loja(user,cur_heroi);
			mainMenu(user,cur_heroi);
		}break;
		case 2:
		{	
			int opcao;
			do
			{
				opcao=game(user,cur_heroi);
			}while(opcao==1);
			switch(opcao)
			{
				case 2:mainMenu(user,cur_heroi);break;
				case 3:return 0;break;
			}
			
			
		}break;
		case 3:
		{
			gerenciamentoStatusHeroi(*user,cur_heroi);
			getch();
			mainMenu(user,cur_heroi);
		}break;
		case 4:
		{
			cadastroHeroi(user);
			getch();
			mainMenu(user,cur_heroi);

		}break;
		case 5:
		{
			int cur_heroi;
			int qtd_herois = (*user).qtd_herois;
			
			
			
			char tagsHeroi[qtd_herois][60];
			tagsHerois(*user,tagsHeroi,qtd_herois);
			typeLayout(tagsHeroi,&cur_heroi,qtd_herois);
			getch();
			cur_heroi -= 1;
			mainMenu(user,cur_heroi);
		}break;
		case 6: 
		{
			int config = configuracoesHeroi(user,cur_heroi);
		
			if(config)
			{
				mainMenu(user,cur_heroi);
			}	
		
		}break;
		case 7:
		{
			return 0;
		}break;
	
		default: printf("Opção invalida!");getch();mainMenu(user,cur_heroi);break;
	}

	return 1;
}
int start_game(Cadastro* user,int* heroi_selec,int execute)
{
	
	//setlocale(LC_ALL,"herói");
	int opcao;		
	char tags[3][60];
	tagsStartGame(tags); 
  while(execute)
  {
  					
	typeLayout(tags,&opcao,2);
	
	switch(opcao)
	{
		case 1: 
		{
		
			int qtd_herois = (*user).qtd_herois;
			char tagsHeroi[qtd_herois+1][60];
			tagsHerois(*user,tagsHeroi,qtd_herois);
			typeLayout(tagsHeroi,heroi_selec,qtd_herois);
			*heroi_selec -= 1;
			return mainMenu(user,*heroi_selec);	
		}break;
	
		case 2:
		{
			return 0;
		}
		default: printf("\nOpção Inválida!\n");	opcao = 1;break;
	}
		
  }
	
	return 0;
				
}



int telaInicial()
{
//	setlocale(LC_ALL,"");
	

	
	system("cls");
	system("color 2F");
	printf("\n\nBem-Vindo!\n");	

	while(1)
	{

 	
	
		char tags[3][60];
		tagsStartMenu(tags);
		int escolha;
		typeLayout(tags,&escolha,2);
		
		
	
		
		while(escolha==1)
		{
			//A funcao de cadastro retorna 0 se o usuario ja existir
			//Se nao ela realiza o armazenamento do usuario em vetor de usuarios
		
				
			if (cadastroUsuarios())
			{
		
				
	            printf("\nCadastro realizado com sucesso!\n");
	          	system("pause");
				escolha = 2; 
			}
			else
			{
				printf("\n\nNome do usuario ja em uso, digite um novo nome do usuario.\n");
				system("pause");
			}
	
		}
	
		
		system("cls");
	
		printf("\nBem vindo ao login\n\n");
	

	// a funcao login eh inciada 
	// Se ela retornar 0 siginifica que houve um erro no login
	//Se retorna 1 o acesso foi liberado
		int qtd_users,p_userOn;
		int menu;
		atribuirQtdUsuarios(&qtd_users);
		Cadastro users[qtd_users];
		preencherStructCadastro(&users[0],qtd_users);
			
		int heroi_selec;
	 if(SingIn(&p_userOn))
	 {
	 	if(users[p_userOn].qtd_herois==0)
	 	{
	 		cadastroHeroi(&users[p_userOn]);
			salvarStructCadastro(users,qtd_users);
		}
		start_game(&users[p_userOn],&heroi_selec,1);
		//users[p_userOn].heroi[heroi_selec].ataque_base = 15;
		//users[p_userOn].heroi[heroi_selec].defesa_base = 15;

		salvarStructCadastro(users,qtd_users);
	 }
	 else
	 {	
		return 0;
	 } 
	   return 1;	
	}
}

void main()
{
	
//	setlocale(LC_ALL,"");
//	intro_torre();
// sound_track();
//	getch();
	int reply;
    do
    {
    	
	 if(telaInicial())
	 {
	 	printf("\n\nVolte Sempre\n\nSaindo...");
	 	getch();
		reply =0;
	 }
	 else
	 {
	 	printf("\nLogin ou senha invalidos!\n");
	 	reply = 1;
	 }
	 
    }while(reply);
		
}

