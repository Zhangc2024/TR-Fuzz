/*
 * Print Celsuis to Fahrenheit table
 */

#include <stdio.h>

int
main(void)
{
	double celsuis, fahr;
	int lower, upper, step;

	lower = 0;	/* Lower limit of temperature table */
	upper = 300;	/* Upper limit of temperature table */
	step = 20;	/* Step size of temperature table */

	printf("Celsuis Fahr\n");

	celsuis = lower;
	while (celsuis <= upper) {
		fahr = (9.0/5.0 * celsuis) + 32.0;
		printf("%3.0f %9.1f\n", celsuis, fahr);
		celsuis += step;
	}

	return 0;
}

