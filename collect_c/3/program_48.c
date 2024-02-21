// print factors of a positive numbers

#include <stdio.h>

int main()
{
    int i, num;

    printf("Please enter a positive number: ");
    scanf("%d", &num);

    printf("Factors of %d are:\n", num);

    for (i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}