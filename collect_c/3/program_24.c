// read input from the user until a positive integer is entered and print the sum at the end

#include <stdio.h>

int main()
{
    int i, n, sum = 0;

    do
    {
        printf("Enter a positive integer: ");
        scanf("%d", &n);
    } while (n <= 0);

    for (i = 1; i <= n; i++)
    {
        sum += i;
    }

    printf("Sum = %d.\n", sum);

    return 0;
}