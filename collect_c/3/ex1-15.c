#include <stdio.h>

float fahr_to_celsius(int fahr);

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
main()
{
	float fahr;
	int lower, upper, step;

	lower = 0;      /* lower limit of temperature table */
	upper = 300;    /* upper limit */
	step = 20;      /* step size */

	fahr = lower;
	while (fahr <= upper) {
		printf("%3.0f %6.1f\n", fahr, fahr_to_celsius(fahr));
		fahr = fahr + step;
	}
}

/* Convert Fahrensheit to Celsius */
float fahr_to_celsius(int fahr) {
	return (5.0/9.0) * (fahr-32);
}
