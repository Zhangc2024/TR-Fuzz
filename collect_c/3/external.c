#include <stdio.h>

void testMe();

int main() {
    testMe();

    return 0;
}

void testMe() {
    extern int test;
    printf("%d\n", test);
}

/**
 * I've declared this variable below the function to show the required usage of extern, otherwise this would normally
 * be at the top of the file.
 *
 * This also occurs if the variable is declared outside of this file.
 */
int test = 1;