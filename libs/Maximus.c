#include <stdio.h>
int max(int A[],int n)
{
	int x;
	
	if(n==0)
	{
		return A[n];
	}
	else
	{
		if(x==A[n-1])
			if(x>A[n])
				return x;
			else
				return A[n];
		
	}
}
main()
{
	int i,A[100];
	for(i=0;i<100;i++)
		A[i] = i;
	
	int maximus = max(A,100);
	printf("maximus: %i\n",maximus);	
	
}
