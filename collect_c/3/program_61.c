// check if the integer can be expressed as sum of two prime numbers

#include <stdio.h>

int checkPrime (int n);

int main()
{
	int i, n;

	printf("Please enter a positive integer: ");
	scanf("%d", &n);

	for (i = 2; i < n; i++)
	{
		if (checkPrime(i) == 1 && n - i != 1 && checkPrime(n - i) == 1)
		{
			printf("%d can be expressed as the sum of %d and %d.\n", n, i, n - i);
			break;
		}
	}

	return 0;
}

int checkPrime (int n)
{
	int i;
	
	for (i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			return 0;
			break;
		}
	}

	return 1;
}
