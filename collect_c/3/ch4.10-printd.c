#include <stdio.h>

void printd(int n)
{
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / 10) 
		printd(n / 10);
	putchar(n % 10 + '0');
}

main(){
	int n;
	n = 123;
	printd(n);
}
