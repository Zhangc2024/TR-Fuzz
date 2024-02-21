#include <stdio.h>

float fahrToCelsius(float);

int main() {
    float fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("%4s\t%7s\n", "fahr", "celsius");
    while (fahr <= upper) {
        printf("%4.0f\t%7.1f\n", fahr, fahrToCelsius(fahr));
        fahr += step;
    }
}

float fahrToCelsius(float fahr) {
    return 5.0 * (fahr - 32) / 9.0;
}

