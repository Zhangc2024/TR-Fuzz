/*
 * Print Fahrenheit to Celsuis table in reverse order.
 */

#include <stdio.h>

#define	LOWER	0	/* Lower limit of table */
#define	UPPER	300	/* Upper limit of table */
#define	STEP	20	/* Step size of table */

int
main(void)
{
	int fahr;

	printf("Fahr Celsuis\n");

	for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
		printf("%3d %6.1f\n", fahr, 5.0 / 9.0 * (fahr - 32));
	
	return 0;
}

