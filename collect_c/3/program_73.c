// perform multiplication operation on two matrices

#include <stdio.h>

int main()
{
	int i, j, k;
	int r1, c1, m1[100][100];
	int r2, c2, m2[100][100];
	int m3[100][100];

	printf("Please enter rows in first matrix: ");
	scanf("%d", &r1);

	printf("Please enter columns in first matrix: ");
	scanf("%d", &c1);

	printf("Please enter rows in second matrix: ");
	scanf("%d", &r2);

	printf("Please enter columns in second matrix: ");
	scanf("%d", &c2);

	printf("Please enter values for first matrix:\n");
	for (i = 0; i < r1; i++)
	{
		for (j = 0; j < c1; j++)
		{
			printf("m1[%d][%d]: ", i, j);
			scanf("%d", &m1[i][j]);
		}
	}

	printf("Please enter values for second matrix:\n");
	for (i = 0; i < r2; i++)
	{
		for (j = 0; j < c2; j++)
		{
			printf("m2[%d][%d]: ", i, j);
			scanf("%d", &m2[i][j]);
		}
	}

	if (c1 != r2)
	{
		printf("The number of columns in first matrix are not equal to the number of rows in second matrix.\n");
		return -1;
	}

	for (i = 0; i < r1; i++)
	{
		for (j = 0; j < c2; j++)
		{
			m3[i][j] = 0;
			for (k = 0; k < c1; k++)
			{
				m3[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}

	printf("Resulting matrix is:\n");
	for (i = 0; i < r1; i++)
	{
		for (j = 0; j < c2; j++)
		{
			printf("%d ", m3[i][j]);
		}
		printf("\n");
	}

	return 0;
}
