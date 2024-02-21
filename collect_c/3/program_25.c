// find the factorial of the number

#include <stdio.h>

int main()
{
    int i, n;
    unsigned long long fact = 1;

    printf("Please enter an integer: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Factorial of the negative number does not exist.\n");
    }
    else if (n == 0)
    {
        printf("Factorial of 0 is 1.\n");
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            fact *= i;
        }

        printf("Factorial of %d is: %llu.\n", n, fact);
    }

    return 0;
}