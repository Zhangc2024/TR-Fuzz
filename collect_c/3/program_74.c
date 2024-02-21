// print the transpose of a matrix using loops

#include <stdio.h>

int main()
{
	int m[10][10], t[10][10], i, j, r, c;

	printf("Please enter number of rows in the matrix: ");
	scanf("%d", &r);

	printf("Please enter number of columns in the matrix: ");
	scanf("%d", &c);

	printf("Please enter the matrix:\n");
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("m[%d][%d]: ", i, j);
			scanf("%d", &m[i][j]);
		}
	}

	for (i = 0; i < c; i++)
	{
		for (j = 0; j < r; j++)
		{
			t[i][j] = m[j][i];
		}
	}

	printf("Transposed matrix:\n");
	for (i = 0; i < c; i++)
	{
		for (j = 0; j < r; j++)
		{
			printf("%d ", t[i][j]);
		}
		printf("\n");
	}

	return 0;
}
