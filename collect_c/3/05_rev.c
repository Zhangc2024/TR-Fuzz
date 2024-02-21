#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
    printf("%4s %8s\n", "fahr", "celsius");
    for(int fahr=UPPER; fahr >= LOWER; fahr-=STEP) {
        printf("%4d %8.1f\n", fahr, (5.0/9.0) * (fahr-32));
    }
}