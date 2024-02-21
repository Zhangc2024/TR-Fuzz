#include<stdio.h>
int main(){
    int factorial=1, num,i;
    printf("enter value of number : ");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        factorial = factorial*i;
    }
    printf("factorial of %d is : %d",num,factorial);
}