/* Pointers to functions:
 *
 * - It is possible to declare a pointer pointing to a function, which can then
 *   be used as an argument in another function.
 *
 * - A pointer to a function is declared as:
 *      type (*pointerName)()
 */

#include <stdio.h>

int sum(int x, int y){
    return x + y;
}

main(){
    int (*fp)(int, int);
    fp = sum;
    int s = fp(10, 20);
    printf("Sum is: %d\n", s);
}
