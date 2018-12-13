#ifndef GERACODE_H
#define GERACODE_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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
	char final_code[] = "0";
	char aux[3];
	while(check<size)
	{
		code = string[check]%prime[check];
		sprintf(aux,"%i",code);
		strcat(final_code,aux);
		check++;
	}

	*codeDest = atoi(final_code);
}
#endif
