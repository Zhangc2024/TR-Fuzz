#include <stdio.h>

void productTable(int n)
{
    int i;
    printf("\nMultiplication Table of %d\n", n);

    for (i = 1; i <= 20; i++)
        printf("\n%-3dx%-3d=%-4d", n, i, n * i);

    return 0;
}

int main()
{
    productTable(2);
}