// perform addition operation on complex numbers using structs

#include <stdio.h>

typedef struct complex {
	int real;
	int img;
} complex;

complex getSum (complex cmp1, complex cmp2);

int main()
{
	complex cmp1, cmp2, result;

	printf("Please enter first complex number: ");
	scanf("%d %d", &cmp1.real, &cmp1.img);

	printf("Please enter second complex number: ");
	scanf("%d %d", &cmp2.real, &cmp2.img);

	result = getSum(cmp1, cmp2);

	printf("Resulting complex number: %d + i%d.\n", result.real, result.img);

	return 0;
}

complex getSum(complex cmp1, complex cmp2)
{
	complex temp;

	temp.real = cmp1.real + cmp2.real;
	temp.img = cmp1.img + cmp2.img;

	return temp;
}
