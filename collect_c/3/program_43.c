// print all the prime numbers between two numbers

#include <stdio.h>

int main()
{
    int low, high, i, flag;

    printf("Please enter two numbers for the intervals: ");
    scanf("%d %d", &low, &high);

    printf("Prime numbers between %d and %d are:\n", low, high);

    while (low < high)
    {
        flag = 0;

        for (i = 2; i <= low / 2; i++)
        {
            if (low % i == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            printf("%d ", low);
        }
        low++;
    }

    printf("\n");

    return 0;
}