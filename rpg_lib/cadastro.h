#ifndef CADASTRO_H
#define CADASTRO_H
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
typedef struct{
	char nome[50];
	float ataque,defesa,vida;
	int tier,ouro,tipo;
}Inimigo;
typedef struct{
    float atributo_1,atributo_2,atributo_3,atributo_4;
    int preco;
    char nome[30];
}Item;

typedef struct{
    int hp,mana,debuff;
	Item capacete,colete,ombro,luvas,calca,botas,mao_direita,mao_esq;
}Inventario;
typedef struct
{
  float ataque_base,vida_base,defesa_base,mana_base;
  float ataque,defesa,vida,mana;
}SubClass;
typedef struct {
  char nome[20];
  int classe;
  float ataque_base,vida_base,defesa_base,mana_base;
  float ataque,defesa,vida,mana;
  int Iv,ultimo_andar,moeda,kit[9],andar,code;
  SubClass subclasse;
  Inventario set;
}Personagem;

typedef struct
{
	char  nome[20];
	char  senha[6];
	int qtd_herois;
	int login_code,passw_code;
	int user_status;
	Personagem heroi[10];
}Cadastro;
void gerarNumPrimo(int prime[])
{
	int check =0;
	int size;
	int code = 0;
	int i;
	int check_prime;
	
	int j = 0;	

			
	while(j<10)
	{		
		i = 1;				
		while(i<=check)
		{	
			if(check%i == 0)
			{
				check_prime++;
			}
			i++;
		}
		if(check_prime==2)
		{
			prime[j] = check;
			j++;
		}
		check++;
		check_prime = 0;	
	}
	
}
void gerarCodigo(char string[],int* codeDest)
{
	
	int check =0;
	int size;
	int code = 0;
	int i;
	int prime[10];
	int check_prime;
	
	int j = 0;	
	size = strlen(string)-1;
	gerarNumPrimo(prime);	
	
	check = 0;
	int final_code[10];
	char aux[2];
	int num = 0;
	while(check<size)
	{
		code = string[check]%prime[check];
		final_code[check] = code;
		check++;
	}
	check = size-1;
	size = 0;
	int divisor = 0;

	while(check>0)
	{
		code += final_code[check];
		if(final_code[check]>final_code[check-1])
		{
			final_code[check] = final_code[check-1];
			divisor += 	final_code[check];	
		}
		else
		{
			if(divisor>final_code[check])
			{
				divisor -= 	final_code[check];		
			}
			else
			{
				divisor += final_code[check];
			}
		
		}
	
		check--;
	}

	*codeDest = code;
}

void atualizarQtdUsuarios(int* new_qtdUsuarios)
{
	setlocale(LC_ALL,"");
	
	int qtd_users = *new_qtdUsuarios;

	FILE* file;

	file = fopen("qtd_users.bin","wb");
	if(file==NULL && qtd_users>1)
	{
		printf("Erro na abertura do arquivo!\n");
		system("pause");
		exit(1);
	}
	int tot_record  = fwrite(&qtd_users,sizeof(int),1,file);
	if(tot_record != 1)
	{
		printf("\nErro gravação do arquivo!\n");
		printf("\nTotal Gravado: %i\n",tot_record);
		system("pause");
		fclose(file);	
		exit(1);
	}	
	fclose(file);
}
void atribuirQtdUsuarios(int *var_qtdUsers)
{
	int qtd_users;
	FILE* file;
	file = fopen("qtd_users.bin","rb");
	if(file==NULL)
	{
		fclose(file);
		qtd_users = 0;
		atualizarQtdUsuarios(&qtd_users);
		file = fopen("qtd_users.bin","rb");
	}

	int tot_read  = fread(&qtd_users,sizeof(int),1,file);

	if(tot_read != 1)
	{
		printf("\nErro Na leitura do arquivo 'qtd_users.bin'!\n");
		fclose(file);
		system("pause");	
		exit(1);
	}	
	fclose(file);

	*var_qtdUsers = qtd_users;
}
int verificarDispLogin(Cadastro users[],int code)
{

	int qtd_users;
	atribuirQtdUsuarios(&qtd_users);

	int i;
	for(i=0;i<qtd_users;i++)
	{
		if(users[i].login_code==code)
		{
			return 0;	
		}
	}

	return 1;
}
void solicitarLogin(Cadastro* user)
{
	setlocale(LC_ALL,"");	

    printf("ATENCÃO: Limite de 10 caracteres; não utilize espaços.\n");
	
	printf("\nDigite um login: ");
	scanf("%s",(*user).nome);
    
    
    while(strlen((*user).nome)>10 ||strlen((*user).nome)==0)
	{
		printf("\nLogin acima do limite caracteres permitido\n");
		printf("\nDigite um novo nome para o úsuario: ");
		scanf("%s",(*user).nome);
	}	  	
}
void solicitarSenha(Cadastro* user)
{
	printf("\n\nATENCÃO: Sua senha deve conter exatamente 6 caracteres; não utilize espaços.\n");
	printf("Digite uma senha: ");
	scanf("%s",(*user).senha);
	
	while(strlen((*user).senha)<6 || strlen((*user).senha)> 6)
	{
		printf("\nSenha com número incorreto de caracteres!\n");
		printf("\nDigite uma nova senha: ");
		scanf("%s",(*user).senha);
	}	
}

//Funções de salvamento e leitura da struct
void salvarStructCadastro(Cadastro users[],int tam)
{
		
	FILE* file;
	file = fopen("struct.txt","wb");
	
	int tot_write = fwrite(users,sizeof(Cadastro),tam,file);

	if(tot_write != tam)
	{
		printf("\nErro gravação do arquivo struct!\n");
		printf("\nTotal Gravado: %i\n",tot_write);
		printf("\nPrevisto: %i\n",tam);
		system("pause");
		fclose(file);	
		exit(1);
	}
	fclose(file);
}

void preencherStructCadastro(Cadastro* user,int p_newUser)
{
	
	FILE* file;
	


	file = fopen("struct.txt","rb");
	if(file == NULL)
	{
		printf("Erro!: Arquivo struct.txt ainda inexistente!\n");
		system("pause");
	}
	else
	{
		int i;
		int tot_read = 0;
		int prev_read = p_newUser;
		
		for(i=0;i<prev_read;i++)
		{
		
			tot_read += fread(user,sizeof(Cadastro),1,file);
			user++;
		}
	
		if(tot_read != prev_read)
		{
			printf("\npreencherStructCadastro(): Erro Na leitura do arquivo struct!\n");
			printf("\nTotal lido: %i\n",tot_read);
			printf("\nTotal previsto: %i\n",prev_read);
			system("pause");	
			fclose(file);
			exit(1);
		}	
	
		
		fclose(file);
	
	}
			
}
///////////////////////////////////
int cadastroUsuarios(void)
{
	system("cls");
	setlocale(LC_ALL,"");
	printf("\nBem-Vindo ao cadastro!\n\n");
	int p_newUser;
	atribuirQtdUsuarios(&p_newUser);
	Cadastro user[p_newUser],u;
	
	if(p_newUser>0)
	{	
		preencherStructCadastro(&user[0],p_newUser);	
	}
	int i;
	int tam = p_newUser;


	
	solicitarLogin(&user[p_newUser]);
	
	int code;

	gerarCodigo(user[p_newUser].nome,&code);

	
	if(verificarDispLogin(user,code))
	{	
		
		solicitarSenha(&user[p_newUser]);
		
	
		user[p_newUser].user_status = 1;
		gerarCodigo(user[p_newUser].nome,&user[p_newUser].login_code);
		gerarCodigo(user[p_newUser].senha,&code);
		user[p_newUser].passw_code = code;
		user[p_newUser].qtd_herois = 0;
		p_newUser++;
		salvarStructCadastro(user,p_newUser);
	
		
		atualizarQtdUsuarios(&p_newUser);
		
		return 1;
	}
	else
	{
		return 0;	
	}		
}

int verificarLogin(int login_code,int* p_userOn)
{
	
	int qtd_users;
	
	atribuirQtdUsuarios(&qtd_users);
	Cadastro users[qtd_users];

	preencherStructCadastro(&users[0],qtd_users);
	
	
	int i;
	
	for(i=0;i<qtd_users;i++)
	{
		if(users[i].login_code==login_code)
		{
			*p_userOn = i;
			return 1;
		}
	
	}

	return 0;
}
int verificarSenha(int passw_code)
{
	int qtd_users;
	
	atribuirQtdUsuarios(&qtd_users);
	Cadastro users[qtd_users];
	
	preencherStructCadastro(&users[0],qtd_users);
	int i;
	for(i=0;i<qtd_users;i++)
	{
		
		if(users[i].passw_code==passw_code)
		{
		
			return 1;
		}
	}
	return 0;
}
int SingIn(int* p_userOn)
{
	
	char login[10];
	char senha[6];


	printf("Digite seu login: ");
	scanf("%s", login);
	printf("Digite sua senha: ");
  
  //Escondendo a senha
	int i = 0;
   
	while(i < 6) 
	{
		
		senha[i] = getch();
		putch('*');
		i++;
	}

	getchar();
	getchar();
	int login_code,passw_code;
	gerarCodigo(login,&login_code);
	gerarCodigo(senha,&passw_code);

	if(verificarLogin(login_code,p_userOn))
	{
		if(verificarSenha(passw_code))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
	
}
void imprimirHeroisDisp(Cadastro user)
{
	system("cls");
	setlocale(LC_ALL,"");
	
	int i;
	printf("\n\nHeróis Disponíveis: %i\n\n",user.qtd_herois);
	
	for(i=0;i<user.qtd_herois;i++)
	{
		printf("%i.%s\n",i+1,user.heroi[i].nome);		
	}
}
#endif
