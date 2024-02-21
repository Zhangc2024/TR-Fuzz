// program to find sum of series of 5 numbers inputted through keyboard.

#include <stdio.h>
int main()
{
    int i, j;
    int k = 65;
    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= 5; j++)
            printf("%c", k++ );

        printf("\n");
    }

    return 0;
}
