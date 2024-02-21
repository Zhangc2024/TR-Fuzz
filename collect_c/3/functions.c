#include <stdio.h>

/**
 * Function prototypes need not have variable names in the arguments.
 *
 * @return
 */
int power(int, int);

int main() {
    int i;

    for(i = 0; i < 10; ++i) {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }

    return 0;
}

/**
 * Passed by value with the exception of arrays or pointers.
 *
 * @param base
 * @param n
 * @return
 */
int power(int base, int n) {
    int i, p;

    p = 1;

    for(i = 1; i <= n; ++i) {
        p = p * base;
    }

    return p;
}
