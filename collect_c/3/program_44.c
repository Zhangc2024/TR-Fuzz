// print all the prime numbers between two numbers when the greater number is entered

#include <stdio.h>

int main()
{
    int i, low, high, flag, temp;

    printf("Please enter two numbers: ");
    scanf("%d %d", &low, &high);

    if (low > high)
    {
        temp = low;
        low = high;
        high = temp;
    }

    printf("Prime numbers between %d and %d:\n", low, high);

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