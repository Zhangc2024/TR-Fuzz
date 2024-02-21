#include <stdio.h>
int main()
{
	int qator, ustun;
	for (qator=1; qator<=4; qator++)
	{
		for (ustun=1; ustun<=qator; ustun++)
		{
			printf(" %d", qator);
		}
		printf("\n");
	}
	return 0;
}
