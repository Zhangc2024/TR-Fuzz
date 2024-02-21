// find the gcd of two numbers using while loop and if...else statement

#include <stdio.h>

int main()
{
    int n1, n2;

    printf("Please enter two positive numbers: ");
    scanf("%d %d", &n1, &n2);

    while (n1 != n2)
    {
        if (n1 > n2)
        {
            n1 -= n2;
        }
        else
        {
            n2 -= n1;
        }
    }

    printf("G.C.D. is %d.\n", n1);

    return 0;
}