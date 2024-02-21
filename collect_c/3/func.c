#include <stdio.h>

void sayHello()
{
    printf("\nHello!");
}

void greet()
{
    printf("\nGood Afternoon!!!");
}

void printBigger(int a, int b)
{
    if (a > b)
        printf("\nBiggest is %d", a);
    else
        printf("\nBiggest is %d", b);
}

int findBigger(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{

    printf("Hiii");
    // sayHello();
    // sayHello();
    // sayHello();
    // greet();
    // greet();

    // printBigger(100, 15);
    // printBigger(100, 151);
    // printBigger(10, 15);

    // int r;
    // r = findBigger(14,6);

    // printf("\n Result : %d", r);

    return 0;
}