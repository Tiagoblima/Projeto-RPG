#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

int main(){
char edge = '|';
char limSup[] = "	|-----------------------------------------------|";
int i= 500;
int j = 50;
while(i>0)
{
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
	Sleep(5);
}
printf("        |                    ______                     |\n");
printf("	|                   |      |                    |\n");
printf("	|                   |      |                    |\n");
printf("	|___________________|      |____________________|\n");
system("pause");
}
