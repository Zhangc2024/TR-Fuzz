/*Pattern 3

         •
       • •
     • • •
   • • • •
 • • • • •
*/
#include<stdio.h>
#include<conio.h>

void main()
{
    char ch = '*';
    int n,i, j, no_of_spaces = 0, spaceCount;

    printf("Enter number : ");
    scanf("%d", &n);
    printf("\n");
    no_of_spaces = n - 1;

    for (i = 1; i <= n; i++)
    {
        for (spaceCount = no_of_spaces; spaceCount >= 1; spaceCount--)
        {
            printf("  "); 
        }
        for (j = 1; j <= i; j++)
        {
            printf("%2c", ch);
        }
        printf("\n");
        no_of_spaces--;
    }
    getch();
}
