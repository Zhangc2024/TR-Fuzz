// power of a number using the while loop

#include <stdio.h>

int main()
{
    int base, exp;

    long long result = 1;

    printf("Enter the base of the number: ");
    scanf("%d", &base);

    printf("Enter the exponent of the number: ");
    scanf("%d", &exp);

    while (exp != 0)
    {
        result *= base;
        --exp;
    }

    printf("Answer: %lld.\n", result);

    return 0;
}