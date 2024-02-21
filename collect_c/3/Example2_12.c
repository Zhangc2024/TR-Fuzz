#include<stdio.h>

int bitcount(unsigned x);

main() {

	unsigned x;
	
	printf("Enter a number: ");
	scanf("%d", &x);
	
	printf("%i\n", bitcount(x));

}

 /* bitcount: count 1 bits in x */
int bitcount(unsigned x) {
	
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
			
	return b;

}
