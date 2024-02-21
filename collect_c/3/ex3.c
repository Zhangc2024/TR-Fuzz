#include <stdio.h>

/* program to print the corresponding Celsius to Feranheit table. Exercise 1-4 */

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0; /* lower limit of temperature table */
    upper = 300; // upper limit
    step  = 20; // step size

    celsius = lower;

    printf("%s | %s\n", "Celsius", "Farenheit");
    printf("======================\n");

    while(celsius <= upper) {

        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f %13.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    
    return 0; //success
}
