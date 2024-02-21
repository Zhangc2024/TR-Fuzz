#include<stdio.h>
int main()
{
    float a;
    int b;
    printf("Type a number : ");
    scanf("%f",&a);
    b = (int)a;
    if((a-b)==0)
    printf("\nThis is an integer");
    else
    printf("\nThis is a fractional number");
    return 0;
}