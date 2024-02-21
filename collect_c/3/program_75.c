// perform cyclic swapping of numbers using call by reference

#include <stdio.h>

void cyclicSwap (int *a, int *b, int *c)
{
	int d;

	d = *b;
	*b = *a;
	*a = *c;
	*c = d;
}

int main()
{
	int a, b, c;

	printf("Please enter three numbers: ");
	scanf("%d %d %d", &a, &b, &c);

	cyclicSwap(&a, &b, &c);

	printf("Numbers after swapping:\n");
	printf("a = %d.\n", a);
	printf("b = %d.\n", b);
	printf("c = %d.\n", c);

	return 0;
}
