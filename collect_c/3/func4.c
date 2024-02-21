#include <stdio.h>

int x = 20;

int foo(int i)
{
    printf("\nfoo - i=%d", i);
    printf("\nfoo - x = %d", x);
}

int main()
{
    int i = 10;
    x = 50;
    foo(i);
    printf("\nmain - x = %d", x);
}