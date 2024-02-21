// C program to print multiplication table of given number.

#include <stdio.h>

int main()
{

    int i, no;
    printf("Please input a number : ");
    scanf("%d", &no);

    i = 1;

    while (i <= 20)
    {
        printf("\n%d x %d = %d", i, no, i * no);
        i++;
    }
    printf("\ni = %d", i);

    return 0;
}