// print inverted half pyramid using *

#include <stdio.h>

int main()
{
	int i, j;
	int input;

	printf("Please enter the number of rows: ");
	scanf("%d", &input);

	for (i = input; i >= 1; i--)
	{
		for (j = 1; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
