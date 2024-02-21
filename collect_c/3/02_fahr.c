#include <stdio.h>

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("%4s\t%7s\n", "fahr", "celsius");
    while (fahr <= upper) {
        celsius = 5.0 * (fahr - 32) / 9.0;
        printf("%4.0f\t%7.1f\n", fahr, celsius);
        fahr += step;
    }
}

