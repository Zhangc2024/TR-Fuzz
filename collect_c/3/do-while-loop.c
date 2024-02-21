/*
    Do While Loop

    The do-while loop. The same as a while loop, except the loop body
    is executed once *before* the test expression. So, at minimum, the code
    inside the do-while body will execute once.
*/

#include <stdio.h>

int main(void)
{
    int number = 10;

    do
    {
        printf("%d ", number--); /* print the number, then decrement its value by 1 */
    } while (number >= 0);

    return 0;
}