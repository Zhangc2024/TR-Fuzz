// print power of a number using recursion

#include <stdio.h>

int getPow(int number, int power)
{
	if (power != 0)
	{
		return number * getPow(number, power - 1);
	}
	return 1;
}

int main()
{
	int number, power;

	printf("Please enter a number and its power to be evaluated: ");
	scanf("%d %d", &number, &power);

	printf("%d ^ %d = %d.\n", number, power, getPow(number, power));
	return 0;
}
