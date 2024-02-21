// find the largest number in three numbers using if statement

#include <stdio.h>

int main()
{
    double n1, n2, n3;

    printf("Please enter three numbers: ");
    scanf("%lf %lf %lf", &n1, &n2, &n3);

    if (n1 >= n2 && n1 >= n3)
    {
        printf("%lf is the largest number.\n", n1);
    }
    if (n2 >= n1 && n2 >= n3)
    {
        printf("%lf is the largest number.\n", n2);
    }
    if (n3 >= n1 && n3 >= n2)
    {
        printf("%lf is the largest number.\n", n3);
    }

    return 0;
}