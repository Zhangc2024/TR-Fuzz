#include <stdio.h>

main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    printf("Celsius\tFahrenheit\n");
    while (celsius <= upper) {
        fahr = (1.8 * celsius) + 32.0;
        printf("%5.0f\t%6.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}