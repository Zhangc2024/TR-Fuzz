// to check if a number is even or odd.

#include <stdio.h>

int main()
{
    int no;
    printf("Please input a number : ");
    scanf("%d", &no);

    if (!(no % 2 == 0))
        printf("It is an not even i.e odd number.");
    else
        printf("It is an even number");

    // if (no % 2 == 0)
    //     printf("It is an even number.");
    // else
    //     printf("It is an odd number");

    return 0;
}