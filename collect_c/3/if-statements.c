/*
    If statements

    In C, we have conditional statements (aka if statements).
    An expression is "tested", and if the result is true, we execute the block
    immediately following the if statement "header".

    If it's false, we go down the conditional chain.

    Note 0: '1' is often used to indicate true, and '0' for false.
    Note 1: The 'bool' type was added in C99

    A longer explanation: https://www.cprogramming.com/tutorial/c/lesson2.html
*/

#include <stdio.h>

int main(void)
{
    int youAreMyFriend = 1;

    if (youAreMyFriend)
    {
        printf("Hey friend!\n");
    }
    else
    {
        printf("Hi! What's your name?\n");
    }

    char youLikeBurgers = 'd'; /* y = yes, n = no, d = depends*/

    if (youLikeBurgers == 'y')
        printf("Me too!\n");
    else if (youLikeBurgers == 'd')
        printf("What does it depend on?\n");
    else
        printf("Why not?");

    return 0;
}