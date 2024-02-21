#include <stdio.h>

#define LOWER   0       /* lower limit of table */
#define UPPER   300     /* upper limit */
#define STEP    20      /* step size*/

/* print Fahrenheit-Celsius table */
float fahrToCelsius(float);

int main()
{
    float fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
        printf("%3.0f   %6.1f\n", fahr, fahrToCelsius(fahr));
    }
    return 0;
}

float fahrToCelsius(float fahr) {
    float celsius;
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    return celsius;
}