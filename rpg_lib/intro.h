#include <stdlib.h>
#include <stdio.h>
//#include <windows.h>
#include <conio.h>
#include <time.h>
#ifndef INTRO_H
#define INTRO_H

int intro_torre(){
char edge = '|';
char limSup[] = "	|-----------------------------------------------|";
int i= 100,a=100,b=100,c=100,d=100;
int j = 50;

while(i>0)
{
	system("color 0C");
	if(i%10==0)
	{
	
		printf("%s\n",limSup);
		
	}
	else if((5+i)%10==0){
		printf("\t%c\t\t\t%i\t\t\t%c\n",edge,j,edge);	
		j--;
	}
	else 
	{
		printf("\t%c\t\t\t \t\t\t%c\n",edge,edge);	
	}

	i--;
}

while(a>0)
{
	system("color 04");
	if(a%10==0)
	{
	
		printf("%s\n",limSup);
		
	}
	else if((5+a)%10==0){
		printf("\t%c\t\t\t%i\t\t\t%c\n",edge,j,edge);	
		j--;
	}
	else 
	{
		printf("\t%c\t\t\t \t\t\t%c\n",edge,edge);	
	}

	a--;
}

while(b>0)
{
	system("color 06");
	if(b%10==0)
	{
	
		printf("%s\n",limSup);
		
	}
	else if((5+b)%10==0){
		printf("\t%c\t\t\t%i\t\t\t%c\n",edge,j,edge);	
		j--;
	}
	else 
	{
		printf("\t%c\t\t\t \t\t\t%c\n",edge,edge);	
	}

	b--;
}

while(c>0)
{
	system("color 02");
	if(c%10==0)
	{
	
		printf("%s\n",limSup);
		
	}
	else if((5+c)%10==0){
		printf("\t%c\t\t\t%i\t\t\t%c\n",edge,j,edge);	
		j--;
	}
	else 
	{
		printf("\t%c\t\t\t \t\t\t%c\n",edge,edge);	
	}

	c--;
}

while(d>0)
{
	system("color 0A");
	if(d%10==0)
	{
	
		printf("%s\n",limSup);
		
	}
	else if((5+d)%10==0){
		printf("\t%c\t\t\t%i\t\t\t%c\n",edge,j,edge);	
		j--;
	}
	else 
	{
		printf("\t%c\t\t\t \t\t\t%c\n",edge,edge);	
	}

	d--;
}

system("color 07");
printf("	|-----------------------------------------------|\n");
printf("	|                                               |\n");
printf("	|                                               |\n");
printf("	|                                               |\n");
printf("        |                    ______                     |\n");
printf("	|                   |      |                    |\n");
printf("	|                   |      |                    |\n");
printf("	|___________________|      |____________________|\n");


system("cls");




system("color 40");


printf("\t __________\t __________\t __________\t __________\t __________\n");

printf("\t|\t   |\t|\t   |\t|    ___   |\t|    ___   |\t|          |\n");

printf("\t|___    ___|\t|    ___   |\t|   |   |  |\t|   |   |  |\t|       ___|\n");

printf("\t    |  |\t|   |   |  |\t|   |___|  |\t|   |___|  |\t|      |___\n");

printf("\t    |  |\t|   |   |  |\t|      ____|\t|      ____|\t|          |\n");

printf("\t    |  |\t|   |   |  |\t|          |\t|          |\t|       ___|\n");

printf("\t    |  |\t|   |___|  |\t|      |   |\t|      |   |\t|      |___\n");

printf("\t    |  |\t|          |\t|      |   |\t|      |   |\t|          |\n");

printf("\t    |__|\t|__________|\t|______|___|\t|______|___|\t|__________|\n");

printf("\n");

printf("\t\t\t\t _________\t __________\n");

printf("\t\t\t\t|         |_\t|\t   |\n");

printf("\t\t\t\t|    ___    |\t|    ___   |\n");

printf("\t\t\t\t|   |   |   |\t|   |   |  |\n");

printf("\t\t\t\t|   |   |   |\t|   |   |  |\n");

printf("\t\t\t\t|   |   |   |\t|   |   |  |\n");

printf("\t\t\t\t|   |   |   |\t|   |   |  |\n");

printf("\t\t\t\t|   |___|   |\t|   |___|  |\n");

printf("\t\t\t\t|          _|\t|          |\n");

printf("\t\t\t\t|_________|\t|__________|\n");

printf("\n");

printf(" _________\t __________\t __________\t __________\t __________\t _____\t   __________ \n");

printf("|         |_\t|          |\t|\t   |\t|\t   |\t|          |\t|     |\t  |\t     |\n");

printf("|    ___    |\t|       ___|\t|      ____|\t|   ____   |\t|      ____|\t|\     |\t  |    ___   |\n");

printf("|   |   |   |\t|      |___ \t|     |____\t|  |    |  |\t|     |____\t|     |\t  |   |   |  |\n");
 
printf("|   |   |   |\t|          |\t|          |\t|  |____|  |\t|\t   |\t|     |\t  |   |   |  |\n");

printf("|   |   |   |\t|       ___|\t|_____     |\t|          |\t|      ____|\t|     |\t  |   |   |  |\n");

printf("|   |___|   |\t|      |___\t _____|\t   |\t|    __    |\t|     |\t\t|     |\t  |   |___|  |\n");

printf("|          _|\t|          |\t|\t   |\t|   |  |   |\t|     |\t\t|     |\t  |          |\n");

printf("|_________|\t|__________|\t|__________|\t|___|  |___|\t|_____|\t\t|_____|\t  |__________|\n");

}
#endif
