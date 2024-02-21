/*
    Constants

    In C, you can create constants! A constant is a fixed value that can't be changed.
    Constants, that hold fixed values, are also known as 'literals'.
    You can use them as regular variables, save the fact that they can't be changed.

    You can define them two different ways... One, using the preprocessor directive '#define'
    The other way is to use the keyword 'const'

    Notice that with const, you also need to define the type
*/

#include <stdio.h>

#define LENGTH 15
#define WIDTH 10

int main(void)
{
    printf("The area of the rectangle is: %d meters squared\n", LENGTH * WIDTH);

    const int BURGERS = 10;
    printf("I dare you to eat %d burgers today!\n", BURGERS);

    const char NEWLINE = '\n';
    printf("Let's go to a new line!%cBoom!", NEWLINE);

    return 0;
}