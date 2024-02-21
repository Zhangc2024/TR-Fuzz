// check if a number is positive or negative using if...else

#include <stdio.h>

int main()
{
    double num;
    printf("Please enter a number: ");
    scanf("%lf", &num);

    if (num <= 0.0)
    {
        if (num == 0.0)
        {
            printf("The number is zero.\n");
        }
        else
        {
            printf("The number is negative number.\n");
        }
    }
    else
    {
        printf("The number is positive.\n");
    }

    return 0;
}