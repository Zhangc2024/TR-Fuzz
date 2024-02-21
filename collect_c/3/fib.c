/* c-examples by A. Shtanyuk */
/* fib.c - fibonacci sequence (1) */

#include <stdio.h>

int fib(int N)
{
	if(N==1 || N==2)
		return 1;
	else
		return fib(N-1)+fib(N-2);
}

int main()
{
	int i;
	for(i=1;i<=45;i++)        // endless !
	   printf("%d\n",fib(i));
	return 0;
}