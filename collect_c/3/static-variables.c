/*
    Static Variables

    C has something called 'static' variables. This means that there is only one location where this variable points to
    (so it's not in the stack). A static variable is initialized once, and then all changes to it that are done in the future
    are cumulative.

    Below, we call randomFunction(), which you would think declares and initializes iAmAStaticVariable to 10, prints 10, and increments it.
    Because it's called a few times, but the function ends and it goes out of scope, it should just print 10 over and over...

    BUT! Because it's static, it's "permanently" there! So, it prints:

    10
    11
    12
    13
*/

#include <stdio.h>

void randomFunction();

int main(void)
{
    randomFunction();
    randomFunction();
    randomFunction();
    randomFunction();

    return 0;
}

void randomFunction()
{
    static int iAmAStaticVariable = 10;

    printf("%d\n", iAmAStaticVariable);

    iAmAStaticVariable++;
}