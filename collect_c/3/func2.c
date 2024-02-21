#include <stdio.h>

#include "mylib.c"

int main()
{
    int x, y, z, big;

    printf("Please input first number : ");
    scanf("%d", &x);

    printf("Please input second number : ");
    scanf("%d", &y);

    printf("Please input second number : ");
    scanf("%d", &z);

    big = big3(x, y, z);

    printf("\n Biggest number is = %d", big);

    return 0;
}
