// program to input week day number and print week day name.

// using else-if-ladder

// using switch-case-default
#include <stdio.h>

int main()
{
    int weekDayNumber;

    printf("Please input week day number (0-6) : ");
    scanf("%d", &weekDayNumber);

    // Multi-way jump statement
    switch (weekDayNumber)
    {
    case 0:
        printf("Sunday");
        break;

    case 1:
        printf("Monday");
        break;

    case 2:
        printf("Tuesday");
        break;

    case 3:
        printf("Wednesday");
        break;

    case 4:
        printf("Thursday");
        break;

    case 5:
        printf("Friday");
        break;

    case 6:
        printf("Saturday");
        break;
    default:
        printf("Invalid Week..");
    }

    return 0;
}
