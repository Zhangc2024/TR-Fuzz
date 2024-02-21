// print full pyramid using *

#include <stdio.h>

int main()
{
	int i, j, k = 0, space;
	int input;

	printf("Please enter the number of rows in the pyramid: ");
	scanf("%d", &input);

	for (i = 1; i <= input; i++, k = 0)
	{
		for (space = 1; space <= input - i; space++)
		{
			printf(" ");
		}
		while (k != (2 * i - 1))
		{
			printf("*");
			k++;
		}
		printf("\n");
	}

	return 0;
}
