#include<stdio.h>
int main(){
    int a,code=0;
    printf("enter the value of a : ");
    scanf("%d",&a);
    for (int i=2;i<=a/2;i++){
        if (a % i == 0)
         code = 1;
    }
        if(code == 0)
        printf("number is prime");
        else 
        printf("number is not prime");
    return 0;
}