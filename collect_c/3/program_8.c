// use of keyword long

#include <stdio.h>

int main()
{
    int a;
    long b;
    long long c;
    double d;
    double long e;

    printf("Size of int variable: %ld bytes.\n", sizeof(a));
    printf("Size of long variable: %ld bytes.\n", sizeof(b));
    printf("Size of long long variable: %ld bytes.\n", sizeof(c));
    printf("Size of double variable: %ld bytes.\n", sizeof(d));
    printf("Size of long double variable: %ld bytes.\n", sizeof(e));

    return 0;
}