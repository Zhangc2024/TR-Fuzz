/*Pattern 4

1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
*/
#include<stdio.h>
#include<conio.h>

void main()
{
    int n, i, j;
    printf("Enter number : ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
    getch();
}
