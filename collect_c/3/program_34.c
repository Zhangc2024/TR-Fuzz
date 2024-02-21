// find lcm using the gcd

#include <stdio.h>

int main()
{
    int i, n1, n2;
    int gcd, lcm;

    printf("Please enter two positive numbers: ");
    scanf("%d %d", &n1, &n2);

    for (i = 1; i <= n1 && i <= n2; i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            gcd = i;
        }
    }

    lcm = (n1 * n2) / gcd;

    printf("GCD = %d. LCM = %d.\n", gcd, lcm);

    return 0;
}