#include<stdio.h>

int bitcount(unsigned x);

main() {

	unsigned x;
	
	printf("Enter a number: ");
	scanf("%d", &x);
	
	printf("%i\n", bitcount(x));

}

int bitcount(unsigned x) {

	int b;
	
	for (b = 0; x != 0; b++)
		x &= (x-1);

	return b;

}
