// calculate the sum of natural numbers using for loop

#include <stdio.h>

int main()
{
    int i, n;
    int sum = 0;

    printf("Enter a natural number: ");
    scanf("%d", &n);

    for (i = 0; i <= n; ++i)
    {
        sum += i;
    }

    printf("Sum = %d.\n", sum);

    return 0;
}