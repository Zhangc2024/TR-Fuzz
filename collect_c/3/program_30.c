// find the gcd of two numbers using for loop and if statement

#include <stdio.h>

int main()
{
    int i, n1, n2, gcd;

    printf("Please enter the number: ");
    scanf("%d %d", &n1, &n2);

    for (i = 1; i <= n1 && i <= n2; i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            gcd = i;
        }
    }

    printf("G.C.D. of %d and %d is %d.\n", n1, n2, gcd);

    return 0;
}