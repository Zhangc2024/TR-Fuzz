// program to find sum of series of 5 numbers inputted through keyboard.

#include <stdio.h>
int main()
{
    int i, sum, no;

    for (i = 1, sum = 0; i <= 5; i++)
    {
        printf("Please input number : ");
        scanf("%d", &no);

        sum = sum + no;
    }

    printf("Sum  = %d", sum);

    return 0;
}