#include <stdio.h>

/* static variables
 * 1. A static variable inside a function keeps its value between invocations
 * 2. A static global variable or a function is "seen" only in the files
 *    it's declared in
 */

void foo() {
    int a = 10;
    static int sa = 10;

    a += 5;
    sa += 5;

    printf("a = %d, sa = %d\n", a, sa);
}

int main () {
    int i;

    for (i = 0; i < 10; ++i)
        foo();
}
