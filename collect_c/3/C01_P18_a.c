#include <stdio.h>

/* Count the characters in input; V1 */

int main() {
    long nc;

    nc = 0;

    while (getchar() != EOF) {
        ++nc;
        printf("%ld\n", nc);
    }
}
