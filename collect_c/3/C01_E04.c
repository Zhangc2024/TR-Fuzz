#include <stdio.h>

/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 */

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;	/* lower limit of temperature table */
    upper = 300;	/* upper limit of temperature table */
    step = 20;	/* step size */
    celsius = lower;

    printf("%3s\t%4s\n", "Celsius", "Fahr");

    while (celsius <= upper) {
        fahr = celsius * (9.0 / 5.0) + 32.0;
        printf("%7.0f\t%4.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
