/* just like normal data pointers, a function pointer can be passed as an
 * argument and can also be returned from a function
 *
 * This is very useful in C as it can be used to avoid code redundany.
 */

#include <stdio.h>

void fun_one() { printf("Fun One\n"); }
void fun_two() { printf("Fun Two\n"); }

void wrapper(void (*fun)()) { fun(); }

int main() {
    wrapper(fun_one);
    wrapper(fun_two);
    return 0;
}
