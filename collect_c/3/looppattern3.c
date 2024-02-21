//5-masala
#include <stdio.h>
int main()
{
	int i,j,k;
	int z=1;
	int n=4;
	
	for (i=1; i<=n; i++)
	{
		for (j=n-1; j>=i; j--)
		{
			printf(" ");
		}
		for (k=1; k<=z; k++)
		{
			printf(" %d", i);
		}
		z+=1;
		printf("\n");
	}
	return 0;
}
