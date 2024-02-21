// count the number of digits

#include <stdio.h>

int main()
{
    long long n;
    int count = 0;

    printf("Please enter an integer: ");
    scanf("%lld", &n);

    while (n != 0)
    {
        n /= 10;
        ++count;
    }

    printf("Number of digits: %d.\n", count);

    return 0;
}