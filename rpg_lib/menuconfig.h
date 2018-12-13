#ifndef MENUCONFIG_H
#define MENUCONFIG_H
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
int defineOptions(char opcoes[][60],int number_option)
{
	if(number_option<1)
	{
		return 0;
	}
	setlocale(LC_ALL,"");
	int i;
	for(i=0;i<=number_option;i++)
	{
		if(i==0)
		{
			strcpy(opcoes[i],"Null\0");
		}
		else
		{
			printf("Digite a opcao[%i]: ",i);
			getchar();
			gets(opcoes[i]);
			getchar();
			strcat(opcoes[i],"\0");
		}
	}

}
int changeOption(char option[][60],int option_positon)
{
	printf("Define the new option tag: ");
	getchar();
	gets(option[option_positon]);
	getchar();
}
void printMenu(char menu_name[60],char opcoes[][60],int qtd_opcoes)
{
	setlocale(LC_ALL,"");
	
	char edge = '+';
	int i,j,k;
	for(i=0;i<=qtd_opcoes;i++)
	{
	
		if(i==0)
		{
			for(j=0;j<32;j++)
			{
				printf(" %c",edge);
				
				if(j==16)
				{
					printf("%s",menu_name);
				}
			}
		
			printf("\n");
		}
		else
		{
			j = i + 1;
			printf("\n%c\t%i.%s",edge,i,opcoes[i]);
			if(qtd_opcoes%2==0)
			{
				printf("\t\t\t");
				printf("\t\t%i.%s",j,opcoes[j]);
			}
			else
			{
				if(j<qtd_opcoes)
				{
					printf("\t\t\t");
					printf("\t\t%i.%s",j,opcoes[j]);
				}
				
			}	
			
			i = j;
		}
	}		
}
void saveMenu(char file_menu[60],char opcoes[][60],int qtd_opcoes)
{
	int set;
	FILE* file;
	file = fopen(file_menu,"wb");
	
	int i;
	for(i=0;i<=qtd_opcoes;i++)
	{
		fwrite(opcoes[i],sizeof(char)*60,1,file);
	}
		
	fclose(file);
}
void fillMenu(char file_menu[60],char opcoes[][60],int qtd_opcoes)
{
	FILE* file;
	file = fopen(file_menu,"rb");
	
	int i;
	int tot_read = -1;
	for(i=0;i<=qtd_opcoes;i++)
	{
		tot_read +=	fread(opcoes[i],sizeof(char)*60,1,file);
	}
	if(tot_read !=qtd_opcoes)
	{
		printf("A leitura do arquivo %s está incorreta\n",file_menu);
		printf("Previsto: %i",qtd_opcoes);
		printf("Lido: %i",tot_read);
	}
	fclose(file);
}
#endif
