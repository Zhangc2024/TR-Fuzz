#include<stdio.h>
int main()
{
    int i,a,b,c;
    printf("Enter total number of elements \n");
    scanf("%d", &c);
    printf("Enter first number ");
    scanf("%d", &b);
    for(i=1;i<=c-1;i++)
    {
        printf("\n Enter another number ");
        scanf("%d",&a);
        if(a>b)
        b=a;
    }
    printf("\n The largest number is %d",b);
    return 0;
}
