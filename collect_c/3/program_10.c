// swapping two numbers without using temporary variable

#include <stdio.h>

int main()
{
    double first, second;

    printf("Enter first number: ");
    scanf("%lf", &first);
    printf("Enter second number: ");
    scanf("%lf", &second);

    first = first - second;
    second = first + second;
    first = second - first;

    printf("After swapping,\n");
    printf("First number: %lf.\n", first);
    printf("Second number: %lf.\n", second);

    return 0;
}