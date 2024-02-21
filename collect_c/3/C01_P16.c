#include <stdio.h>

/* copy input to output; V1 */

int main() {
    int c;

    c = getchar();
    while(c != EOF) {
        putchar(c);
        c = getchar();
    }
}
