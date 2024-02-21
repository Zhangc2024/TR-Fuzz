// print the factorial of a whole number using recursion

#include <stdio.h>

int getFactorial(int n)
{
	if (n == 0)
	{
		return 1;
	}
	return n * getFactorial(n - 1);
}

int main()
{
	int n;

	printf("Please enter a whole number: ");
	scanf("%d", &n);

	printf("Factorial of %d is %d.\n", n, getFactorial(n));

	return 0;
}
