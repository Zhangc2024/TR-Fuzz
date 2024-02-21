// program to find sum of series of 5 numbers inputted through keyboard.

#include <stdio.h>
int main()
{
    int i, j;
    for (i = 1; i <= 5; i++)
    {
        printf("i=%d ", i);
        for (j = 1; j <= i; j++)
            printf("%d", j);
        printf("\n");
    }
    return 0;
}