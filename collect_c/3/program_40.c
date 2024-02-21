// power using pow()

#include <stdio.h>
#include <math.h>

int main()
{
    double base, exp, result;

    printf("Enter a base number: ");
    scanf("%lf", &base);

    printf("Enter the exponent: ");
    scanf("%lf", &exp);

    result = pow(base, exp);

    printf("%lf ^ %lf = %lf.\n", base, exp, result);

    return 0;
}