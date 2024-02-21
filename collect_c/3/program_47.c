// print all the armstrong numbers between two numbers

#include <math.h>
#include <stdio.h>

int main()
{
    int i, n = 0;
    int high, low, temp1, temp2, rem;
    float result = 0.0;

    printf("Please enter two numbers for interval: ");
    scanf("%d %d", &low, &high);

    printf("Armstrong numbers between %d and %d are:\n", low, high);

    for (i = low + 1; i < high; i++)
    {
        temp1 = i;
        temp2 = i;

        while (temp1 != 0)
        {
            temp1 /= 10;
            ++n;
        }

        while (temp2 != 0)
        {
            rem = temp2 % 10;
            result += pow(rem, n);
            temp2 /= 10;
        }

        if ((int)result == i)
        {
            printf("%d ", i);
        }

        n = 0;
        result = 0;
    }

    printf("\n");

    return 0;
}