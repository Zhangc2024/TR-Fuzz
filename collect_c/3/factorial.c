#include <stdio.h>

// 5 ! = 1 * 2 * 3 * 4 * 5
// 5 ! = 5 * 4 * 3 * 2 * 1

// long long factorial(int n)
// {
//     int i;
//     long long fac;

//     fac = 1;
//     for (i = 2; i <= n; i++)
//         fac = fac * i;
//     return fac;
// }

long long factorial(int n)
{
    if (n == 1)
        return 1;

    return n * factorial(n - 1);
}

int main()
{
    int n, i;
    long long result;

    for (i = 1; i <= 25; i++)
    {
        result = factorial(i);
        printf("\n%d! = %lld", i, result);
    }
}
