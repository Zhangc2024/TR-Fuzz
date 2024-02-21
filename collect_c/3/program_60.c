// print all the prime numbers in an interval using functions

#include <stdio.h>

int checkPrimeNumber(int n);

int main()
{
	int n1, n2, i, flag;

	printf("Please enter two postive numbers: ");
	scanf("%d %d", &n1, &n2);

	printf("Prime numbers between %d and %d are: ", n1, n2);

	for (i = n1 + 1; i < n2; ++i)
	{
		if (checkPrimeNumber(i))
		{
			printf("%d ", i);
		}
	}

	printf("\n");

	return 0;
}

int checkPrimeNumber (int n)
{
	int j, flag = 1;

	for (j = 2; j <= n / 2; ++j)
	{
		if (n % j == 0)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}
