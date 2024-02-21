#include <stdio.h>

#include "mylib.c"

int main()
{
    sayHello();
    greet();

    printf("\nxxxx %d", big3(10, 12, 5));
}