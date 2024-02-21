#include <stdio.h>

int power(int a, int b)
{
    int result, i;

    result = 1;
    for (i = 1; i <= b; i++)
        result = result * a;

    return result;
}

int main()
{
    // a power b
    int a, b;

    printf("Please input first number : ");
    scanf("%d", &a);

    printf("Please input second number : ");
    scanf("%d", &b);

    printf("%d power %d is %d", a, b, power(a, b));

    return 0;
}