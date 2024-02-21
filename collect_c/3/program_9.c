// swapping two numbers using a temporary variables

#include <stdio.h>

int main()
{
    double first, second, temp;

    printf("Enter first number: ");
    scanf("%lf", &first);
    printf("Enter second number: ");
    scanf("%lf", &second);

    temp = first;
    first = second;
    second = temp;

    printf("After swapping,\n");
    printf("First number: %lf.\n", first);
    printf("Second number: %lf.\n", second);

    return 0;
}