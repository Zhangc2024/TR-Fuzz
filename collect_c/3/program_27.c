// generate the multiplication table upto a range

#include <stdio.h>

int main()
{
    int i, n, range;

    printf("Please enter the integer: ");
    scanf("%d", &n);

    printf("Please enter range: ");
    scanf("%d", &range);

    for (i = 1; i <= range; i++)
    {
        printf("%d * %d = %d.\n", n, i, n * i);
    }

    return 0;
}