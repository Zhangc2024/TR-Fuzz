// multiply two numbers

#include <stdio.h>

int main() 
{
    double a, b, product;

    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);

    product = a * b;

    printf("Product = %.2lf.\n", product);

    return 0;
}