#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Enter a value ");
    scanf("%d",&a);
    b=a%7;
    c=a%5;
    b==0?printf("Divisible by 7  "):printf("Not divisible by 7  ");
    c==0?printf("Divisible by 5  "):printf("Not divisible by 5  ");
    return 0;
}
