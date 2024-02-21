// perform addition operation of two matrices

#include <stdio.h>

int main()
{
	int r, c, a[100][100], b[100][100], sum[100][100], i, j;

	printf("Please enter number of rows: ");
	scanf("%d", &r);

	printf("Please enter number of columns: ");
	scanf("%d", &c);

	printf("Please enter first matrix:\n");
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	printf("Please enter second matrix:\n");
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			sum[i][j] = a[i][j] + b[i][j];
		}
	}

	printf("Resulting matrix:\n");
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d ", sum[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}
