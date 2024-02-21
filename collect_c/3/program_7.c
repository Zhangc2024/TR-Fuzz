// print the size of different variable types

#include <stdio.h>

int main()
{
    int intType;
    float floatType;
    double doubleType;
    char charType;

    printf("Size of int type: %ld bytes.\n", sizeof(intType));
    printf("Size of float type: %ld bytes.\n", sizeof(floatType));
    printf("Size of double type: %ld bytes.\n", sizeof(doubleType));
    printf("Size of char type: %ld bytes.\n", sizeof(charType));

    return 0;
}