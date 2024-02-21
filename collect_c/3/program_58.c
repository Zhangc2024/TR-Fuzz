// a simple operation calculator

#include <stdio.h>

int main()
{
	char operator;
	double first, second;

	printf("Please enter an operator: ");
	scanf("%c", &operator);

	printf("Please enter two operands: ");
	scanf("%lf %lf", &first, &second);

	switch (operator)
	{
		case '+':
			printf("%.1lf + %.1lf = %.1lf.\n", first, second, first + second);
			break;
		case '-':
			printf("%.1lf - %.1lf = %.1lf.\n", first, second, first - second);
			break;
		case '*':
			printf("%.1lf * %.1lf = %.1lf.\n", first, second, first * second);
			break;
		case '/':
			printf("%.1lf / %.1lf = %.1lf.\n", first, second, first / second);
			break;
		default:
			printf("Invalid operator.\n");
	}

	return 0;
}
