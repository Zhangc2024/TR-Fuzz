// find the roots of a quadratic equation

#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, discriminant;
    double root1, root2;
    double realPart, imagPart;

    printf("Enter the coefficients a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0)
    {
        root1 = (-b + sqrt(discriminant) / (2 * a));
        root2 = (-b - sqrt(discriminant) / (2 * a));

        printf("root1 = %.2lf and root2 = %.2lf.\n", root1, root2);
    }
    else if (discriminant == 0)
    {
        root1 = root2 = (-b + sqrt(discriminant) / (2 * a));

        printf("root1 = root2 = %.2lf.\n", root1);
    }
    else
    {
        realPart = -b / (2 * a);
        imagPart = sqrt(-discriminant) / (2 * a);

        printf("root1 = %.2lf + %.2lfi and root2 = %.2lf - %.2lfi.\n", realPart, imagPart, realPart, imagPart);
    }

    return 0;
}