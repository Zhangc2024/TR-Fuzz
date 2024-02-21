#include<stdio.h>

unsigned rightrot(unsigned x, int n);

main() {

	int n;
	unsigned x;
	
	printf("Enter a number: ");
	scanf("%d", &x);
	printf("Enter the n amount of bits: ");
	scanf("%d", &n);
	
	printf("%i\n", rightrot(x, n));

}


unsigned rightrot(unsigned x, int n) {

	int org = x, m = 1, d2 = x, y;
	
	x =	x & m;	
	x <<= (n - 1);	
	org >>= n;	
	org <<= n;	
	org = org ^ x;	
	d2 >>= 1;
	y = ~(~0 << (n - 1));	
	d2 = d2 & y;
	x = org | d2;
	
	return x;
	
}
