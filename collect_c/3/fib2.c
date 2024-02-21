/* c-examples by A. Shtanyuk */
/* fib2.c - fibonacci sequence (2) */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100


int fib2(int N)
{
	static int arr[MAX]={1,1};
	if(N==1 || N==2)
		return 1;
	else if(N>MAX)
		exit(1);
	else
		return (arr[N]=(arr[N-1]?arr[N-1]:fib2(N-1))+
			           (arr[N-2]?arr[N-2]:fib2(N-2)));
}

int main()
{
	int i;
	for(i=1;i<=45;i++)
	   printf("%d\n",fib2(i));
	return 0;
}