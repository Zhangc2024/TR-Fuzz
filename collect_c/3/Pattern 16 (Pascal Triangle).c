/*Pascal triangle
 
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
*/
#include<stdio.h>
#include<conio.h>

long fact(int);

void main()
{
    int line, i, j;
    
    printf("Enter the number : ");
    scanf("%d", &line);

    for (i = 0; i < line; i++)
    {
        for (j = 0; j < line - i - 1; j++)
        {
            printf(" ");
        }

        for (j = 0; j <= i; j++)
        {
            printf("%ld ", fact(i) / (fact(j) * fact(i - j)));
        }

        printf("\n");
    }
    getch();
}

long fact(int num)
{
    long f = 1;
    int i = 1;

    while (i <= num)
    {
        f = f * i;
        i++;
    }
    return f;
}
/*WITHOUT USING FUNCTION

#include<stdio.h>
#include<conio.h>
void main()
{
    int x, y, n, a, z, s;
 
    printf("Enter the number : ");
    scanf("%d", &n);
    s = n;

    for (x = 0; x <= n; x++)
    {
        a = 1;
        for (z = s; z >= 0; z--)
            printf(" ");

        s--;

        for (y = 0; y <= x; y++)
        {
            printf("%d ", a);
            a = (a * (x - y) / (y + 1));
        }
        printf("\n");
    }
    getch();
}*/
