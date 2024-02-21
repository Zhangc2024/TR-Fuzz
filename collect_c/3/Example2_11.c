#include<stdio.h>

unsigned getbits(unsigned x, int p, int n);

main() {

	int p, n;
	unsigned x;
	
	printf("Enter a number: \n");
	scanf("%d", &x);
	printf("Enter the p position: \n");
	scanf("%d", &p);
	printf("Enter the n amount of bits: (smaller than the previous one)\n");
	scanf("%d", &n);
	
	printf("\n%i\n", getbits(x, p, n));

}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {

	return (x >> (p+1-n)) & ~(~0 << n);
	
}
