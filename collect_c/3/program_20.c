// check if the number is positive or negative using nested if...else

#include <stdio.h>

int main()
{
    double num;

    printf("Enter a number: ");
    scanf("%lf", &num);

    if (num < 0.0)
    {
        printf("%lf is a negative number.\n", num);
    }
    else if (num > 0.0)
    {
        printf("%lf is a positive number.\n", num);
    }
    else
    {
        printf("%lf is zero.\n", num);
    }

    return 0;
}