/*
    For Loop

    The C for loop is another looping construct. However, this not only checks an expression to determine if it
    should continue; it starts with an 'init' step, executed once before the loop. (Ex: to initalize a variable used
    for iteration.) Then, it checks the expression, and after the loop's execution, it checks for an increment step.

    With these 3 steps, you can build powerful loops with shorter code.

    Note: Until C99, declaring variables inside of the for loop 'init' section was not allowed.
*/

#include <stdio.h>

int main(void)
{
    int i, j;

    /* Print 1 to 10 */
    for (i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n\n\n");

    /* Print a multiplication table with nested for loops */
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            printf("%d\t", i * j);
        }
        printf("\n");
    }

    return 0;
}