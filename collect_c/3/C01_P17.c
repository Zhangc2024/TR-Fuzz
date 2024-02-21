#include <stdio.h>

/* copy input to output; V1 */

int main() {
    int c;

    while((c = getchar()) != EOF) {
        putchar(c);
    }
}
