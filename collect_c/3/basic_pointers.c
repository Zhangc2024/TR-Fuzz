#include <stdio.h>

int main() {
    int x = 1, y = 2, z[10];

    int *ip;     /* ip is a pointer to int */

    ip = &x;     /* ip now points to x */

    y = *ip;     /* y is now 1 */
    printf("y is %d\n", y);

    *ip = 0;     /* x is now 0 */
    printf("x is %d\n", x);

    ip = &z[0];  /* ip now points to z[0] */
}
