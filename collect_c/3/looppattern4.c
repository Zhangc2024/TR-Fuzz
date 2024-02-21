//3-masala
#include <stdio.h>
int main()
{
	int qator, ustun, son=1;
	for (qator=1; qator<=4; qator++)
	{
		for (ustun=1; ustun<=qator; ustun++)
		{
			printf(" %d", son++);
		}
		
		printf("\n");
	}
	
	return 0;
}
