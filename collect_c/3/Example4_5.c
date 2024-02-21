#include<stdio.h>

/* printd: print n in decimal*/ 
void printd(int n) {

	if (n < 0) {
		putchar('-');
		n = -n;
	}

	if (n / 10)
		printd(n / 10);
	putchar(n % 10 + '0');

}

main() {
	
	int n;
	printf("Enter a number:\n");
	scanf("%i", &n);
	
	printd(n);
	
}
