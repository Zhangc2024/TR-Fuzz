// find the largest number among three numbers using if...else ladder

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
    else if (n2 >= n1 && n2 >= n3)
    {
        printf("%lf is the largest number.\n", n2);
    }
    else
    {
        printf("%lf is the largest number.\n", n3);
    }

    return 0;
}