// program to find sum of series of numbers terminated by 0.
// ex1. 3 5 3 9 2 0
// ex2 10 13 54 0
#include <stdio.h>
int main()
{
    int sum, no;
    sum = 0;

    // no = -1;
    // while (no != 0)
    // {
    //     printf("Please input number : ");
    //     scanf("%d", &no);

    //     sum = sum + no;
    // }

    do
    {
        printf("Please input number : ");
        scanf("%d", &no);

        sum = sum + no;
    } while (no != 0);

    printf("Sum  = %d", sum);

    return 0;
}