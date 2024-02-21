//Program to print Ascending and descending order of three numbers

#include<stdio.h>
#include<conio.h>
void main()
{
    int a,b,c;
    printf("Enter numbers:");
    scanf("%d %d %d",&a,&b,&c);

    if((a>=b)&&(a>=c))
    {
        if(b>=c)
        {
            printf("\nDescending : %d %d %d",a,b,c);
            printf("\nAscending : %d %d %d",c,b,a);
        }
        else
        {
            printf("\nDescending : %d %d %d",a,c,b);
            printf("\nAscending : %d %d %d",b,c,a);
        }
    }
    else if((b>=a)&&(b>=c))
    {
        if(a>=c)
        {
            printf("\nDescending : %d %d %d",b,a,c);
        }
    }
    else
    {
        if(b>=a)
        {
            printf("\nDescending : %d %d %d",c,b,a);
            printf("\nAscending : %d %d %d",a,b,c);
        }
        else
        {
            printf("\nDescending : %d %d %d",c,a,b);
            printf("\nAscending : %d %d %d",b,a,c);
        }
    }
    getch();
}
