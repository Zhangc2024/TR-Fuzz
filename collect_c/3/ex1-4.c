#include <stdio.h>
/* print Celsius-Fahr table
    for celsius = 0, 20, ..., 300 */
main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;      /* lower limit of temperature table */
	upper = 300;    /* upper limit */
	step = 20;      /* step size */

	celsius = lower;
	printf("Celsius-Fahrenheit Table\n");
	printf("------------------------\n");
	printf("| Celsius | Fahrenheit |\n");
	while (celsius <= upper) {
		fahr = (9.0/5.0) * celsius + 32;
		printf("| %7.0f | %10.0f |\n", celsius, fahr);
		celsius = celsius + step;
	}
	printf("------------------------\n");
}
