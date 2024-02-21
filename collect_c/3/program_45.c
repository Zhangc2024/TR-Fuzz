// check for the armstrong number of three digits

#include <stdio.h>

int main()
{
    int num, originalNum, remainder, result = 0;

    printf("Please enter a three digit number: ");
    scanf("%d", &num);

    originalNum = num;

    while (originalNum != 0)
    {
        remainder = originalNum % 10;

        result += remainder * remainder * remainder;

        originalNum /= 10;
    }

    if (result == num)
    {
        printf("%d is an armstrong number.\n", num);
    }
    else
    {
        printf("%d is not an armstrong number.\n", num);
    }

    return 0;
}