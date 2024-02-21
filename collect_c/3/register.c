#include <stdio.h>

/**
 * Register tells the compiler if possible to place variables into the available registers as they are used a lot!
 *
 * The compiler is free to decided to do this or not! Things like excessive use of register will not cause problems,
 * the compiler will just decided to discard it.
 *
 * @param a
 * @param b
 */
void print_me(register int a, register int b);

int main() {
    register int x = 1;
    register int y = 2;

    print_me(x, y);

    return 0;
}

void print_me(register int a, register int b) {
    printf("%d\t%d\n", a, b);
}