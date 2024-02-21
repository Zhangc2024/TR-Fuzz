#include<stdio.h>

unsigned inverse(unsigned x, int p, int n);

main() {

	int p = 5, n = 3;
	unsigned x;
	
	printf("Enter a number: \n");
	scanf("%d", &x);
	printf("Enter the p position: \n");
	scanf("%d", &p);
	printf("Enter the n amount of bits: (smaller than the previous one)\n");
	scanf("%d", &n);
	
	printf("\n%i\n", inverse(x, p, n));

}


unsigned inverse(unsigned x, int p, int n) {

	int org = x, m = 0, d = ~0;

	x >>= (p + 1 - n);
	m = (~0 << n);
	x = ~(x ^ m);
	x <<= (p + 1 - n);	
	m = ~(~0 << (p - n + 1));
	d <<= (p + 1);
	m = d | m;
	org = org & m;
	x = org | x;
	
	return x;
	
}
