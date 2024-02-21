//Print factors of entered number
#include<stdio.h>
#include<conio.h>
void main()
{
    int n, i;
    printf("Enter a number : ");
    scanf("%d", &n);
    printf("Factors of %d are : ", n);
    for (i = 1; i <= n; ++i)
    {
        if (n % i == 0)
            printf("\n%d ", i);
    }
    getch();
}
