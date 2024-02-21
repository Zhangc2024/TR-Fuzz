#include <stdio.h>
/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;      /* lower limit of temperature table */
	upper = 300;    /* upper limit */
	step = 20;      /* step size */

	fahr = lower;
	printf("Fahrenheit-Celsius Table\n");
	printf("------------------------\n");
	printf("| Fahrenheit | Celsius |\n");
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32);
		printf("| %10.0f | %7.1f |\n", fahr, celsius);
		fahr = fahr + step;
	}
	printf("------------------------\n");
}
