#include <stdio.h>
#include <stdlib.h>

int main(void) {
	//ex 1-3
	float f, c;
	int lo, hi, st;

	lo = -20;
	hi = 150;
	st = 10;

	c = lo;

	printf("Table of Tempreture\n");
	printf("Celsius Fahr\n");
	while (c <= hi) {
		f = 1.8 * c + 32;
		printf("%3.0f     %4.0f\n", c, f);
		c+=st;
	}
}
