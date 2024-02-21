// find sum of all the natural numbers upto n using recursion

#include <stdio.h>

int getSum(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n + getSum(n - 1);
}

int main()
{
	int n;

	printf("Please enter a natural number: ");
	scanf("%d", &n);

	printf("Sum of all the natural numbers upto %d is: %d.\n", n, getSum(n));

	return 0;
}
