/* c-examples by A. Shtanyuk */
/* fib3.c - fibonacci sequence (3) */

#include <stdio.h>
#include <stdlib.h>


int fib_iter(int k,int m,int N)
{
	if(N==1)
		return m;
	else
		return fib_iter(m,k+m,N-1);
}

int fib3(int N)
{
	return fib_iter(0,1,N);
}

int main()
{
	int i;
	for(i=1;i<=45;i++)
	   printf("%d\n",fib3(i));
	return 0;
}