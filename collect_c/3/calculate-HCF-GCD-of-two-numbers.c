#include<stdio.h>
int main(){
    int num1,num2, i,hcf;
    printf("enter value of num1 : ");
    scanf("%d",&num1);
    printf("enter value of num2 : ");
    scanf("%d",&num2);
    
    for (i=1;i<=num1 && i<=num2;i++){
        if(num1%i==0 && num2%i==0)
        hcf = i;
    }
    printf("HCF of %d and %d is : %d",num1,num2,hcf);
    return 0;

}