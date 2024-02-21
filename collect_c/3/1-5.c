#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float f, c;
	int lo, hi, st;

	lo = 0;
	hi = 300;
	st = 20;
	printf("Table of Temprature\n");
	for (f = hi; f >= lo; f -= st) {
		c = (5 / 9.0) * (f - 32);
		printf("%3.0f %6.2f\n", f, c);
	}
}
