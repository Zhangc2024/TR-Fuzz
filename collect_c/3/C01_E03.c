#include <stdio.h>

/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 */

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;	/* lower limit of temperature table */
    upper = 300;	/* upper limit of temperature table */
    step = 20;	/* step size */
    fahr = lower;

    printf("%3s\t%6s\n", "Fahr", "Celsius");

    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%4.f\t%7.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
