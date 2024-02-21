#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
main()
{
    float celsius, fahr;
    float lower, upper, step;

    lower = 0;        /* lower limit of temperature scale */
    upper = 300;      /* upper limit */
    step = 20;        /* step size */

    printf("Temperature Conversion Table:\n");
    printf("Celsius\t\tFahrenheit\n");
    printf("----------------------------\n");
  
    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32;
        printf("%3.0f\t\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}