#include <stdio.h>

int setbits(int x, int n, int p, int y) {

	int i, orig = x;
	int keep, mask = 0;
	
	mask = ~(~0 << n);
	keep = mask & y;
	x >>= (p + n);
	x <<= (p + n);
	x |= (keep << p);
	
	for (i = 0; i < p; i++) {
		mask = 1 << i;
		if ((orig & mask) > 0)  {
			x |= mask;
		}
	}
	
	return(x);
}

int main() {

	int x, p, n, y;
	
	printf("Enter a number: \n");
	scanf("%d", &x);
	printf("Enter the p position: \n");
	scanf("%d", &p);
	printf("Enter the n amount of bits: \n");
	scanf("%d", &n);
	printf("Enter the second number: \n");
	scanf("%d", &y);
	
	printf("%d\n", setbits(x, p, n, y));
  
}
