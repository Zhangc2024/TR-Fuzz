/*
    While Loop

    The while loop is a looping construct in C. The loop body executes as long as the
    test expression evaluates to true. Once it evaluates to false, the loop stops.
    The loop starts with the test (so there's a chance it may never execute), and then if
    the expression is true, executes the body. The expression is tested after every execution
    of the loop's body.
*/

#include <stdio.h>

int main(void)
{
    int number = 0;

    while (number <= 10) {
        printf("%d ", number++); /* print the number, then increment it's value by 1 */
    }

    return 0;
}