#include <stdio.h>
int main() 
{
	int son=0, s=0, n, i;
	printf("n="); scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		son=son*10+i;
		printf("%d", son);
		s+=son;
		if(i!=n)
		{
			printf("+");
		}
		else
		{
			printf("=");
			printf("%d", s);
		}
	}
	return 0;
}
