// print Series and it's sum  ( first 10 natural numbers  : 1 + 2 + 3 + ... + 10 = 55 )

#include <stdio.h>
int main()
{
    int i, sum;

    for (i = 1, sum = 0; i <= 10; i++)
    {
        printf("%d + ", i);
        sum = sum + i;
    }

    printf("\b\b = %d", sum);

    return 0;
}