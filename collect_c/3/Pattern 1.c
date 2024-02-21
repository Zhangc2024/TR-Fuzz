/*Pattern 1

•
• •
• • •
• • • •
• • • • •*/

#include<stdio.h>
#include<conio.h>

void main()
{
    int i, j, n;
    
    printf("Enter number :");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=i; j++)
        {
            printf("• ");
        }
        printf("\n");
    }
    getch();
}
