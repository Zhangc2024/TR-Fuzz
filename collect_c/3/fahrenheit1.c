#include <stdio.h>

#define     LOWER 0
#define     UPPER 300
#define     STEP  20

void main() {
    int int_fahr;

    for(int_fahr = LOWER; int_fahr <= UPPER; int_fahr += 20) {
        printf("%3d %6.1f\n", int_fahr, (5.0 / 9.0) * (int_fahr - 32.0));
    }
}
