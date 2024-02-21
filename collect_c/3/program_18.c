// check a year for a leap year

#include <stdio.h>

int main()
{
    int year;

    printf("Please enter a year: ");
    scanf("%d", &year);

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                printf("%d is a leap year.\n", year);
            }
            else
            {
                printf("%d is not a leap year.\n", year);
            }
        }
        else
        {
            printf("%d is a leap year.\n", year);
        }
    }
    else
    {
        printf("%d is not a leap year.\n", year);
    }

    return 0;
}