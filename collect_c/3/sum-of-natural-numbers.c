#include<stdio.h>
int main(){
    int sum=0, n,i;
    printf("enter value of n : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum += i;
    }
    printf("Sum of %d Natural Numbers is : %d",n,sum);
}