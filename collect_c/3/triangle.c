/* c-examples by A.Shtanyuk */
/* triangle.c - A triangle example */

#include <stdio.h>

int main()
{
	int N,i,j,a=0,b;
	printf("Enter N: ");
	scanf("%d",&N);

	for(i=0;i<2*N;i++)
	{
		if(i>=N) {
			a=i;
			b=2*N-1;
		}
		else
		{
			a=0;
			b=i;
		}
		for(j=a;j<=b;j++)
			putchar('*');
		putchar('\n');
	}
	return 0;
}