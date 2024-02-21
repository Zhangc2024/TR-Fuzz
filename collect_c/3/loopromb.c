//9-masala
#include <stdio.h>
int main()
{
	int qator, ustun, son=9;
	int a=son/2+1;
	for (qator=1; qator<=son; qator++)
	{
		for (ustun=1; ustun<=son; ustun++)
		{
			if (ustun==a || ustun==son-a+1)
			printf("*");
			else
			printf(" ");
		}
		if (qator<=son/2)
		a--;
		else
		a++;
		printf("\n");
	}
	return 0;
}
