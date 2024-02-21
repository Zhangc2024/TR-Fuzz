#include <stdio.h>
#include <stdlib.h>

int main(void) {
	//ex 1-3
	float f, c;
	int lo, hi, st;

	lo = 0;
	hi = 300;
	st = 20;

	f = lo;

	printf("Table of Tempreture\n");
	printf("Fahr Celsius\n");
	while (f <= hi) {
		c = (5.0 / 9.0) * (f - 32.0);
		printf("%4.0f %7.2f\n", f, c);
		f+=st;
	}
}
