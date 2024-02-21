// find gcd of two numbers using recursion

#include <stdio.h>

int hcf (int n1, int n2)
{
	if (n2 != 0)
	{
		return hcf(n2, n1 % n2);
	}
	return n1;
}

int main()
{
	int n1, n2;

	printf("Please enter two natural numbers: ");
	scanf("%d %d", &n1, &n2);

	printf("GCD of %d and %d is %d.\n", n1, n2, hcf(n1, n2));

	return 0;
}
