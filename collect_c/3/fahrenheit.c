#include <stdio.h>

void main() {
    float flt_fahr, flt_celsius;
    int int_lower, int_upper, int_step;

    int_lower = 0;
    int_upper = 300;
    int_step = 20;

    flt_fahr = int_lower;
    while (flt_fahr <= int_upper) {
        flt_celsius = (5.0 / 9.0) * (flt_fahr - 32.0);
        printf("%3.0f\t%6.1f\n", flt_fahr, flt_celsius);
        flt_fahr = flt_fahr + int_step;
    }
}
