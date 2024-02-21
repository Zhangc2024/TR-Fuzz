// find sum of natural numbers using while loop

#include <stdio.h>

int main()
{
    int i, n;
    int sum = 0;

    printf("Enter a natural number: ");
    scanf("%d", &n);

    i = 1;

    while (i <= n)
    {
        sum += i;
        i++;
    }

    printf("Sum = %d.\n", sum);

    return 0;
}