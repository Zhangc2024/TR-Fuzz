/*
 * Print Fahrenheit to Celsuis table using a function call.
 */

#include <stdio.h>

void tempconv(int, int, int);

int
main(void)
{
	int lower, upper, step;

	lower = 0;	/* Lower limit of temperature table */
	upper = 300;	/* Upper limit of temperature table */
	step = 20;	/* Step size of temperature table */

	tempconv(lower, upper, step);

	return 0;
}

void
tempconv(int lower, int upper, int step)
{
	double fahr, celsuis;

	printf("Fahr Celsuis\n");

	fahr = lower;
	while (fahr <= upper) {
		celsuis = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsuis);
		fahr += step;
	}
}
