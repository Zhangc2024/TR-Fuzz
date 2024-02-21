#include<stdio.h>
int main(){
    int num1,num2, i,hcf,lcm;
    printf("enter value of num1 : ");
    scanf("%d",&num1);
    printf("enter value of num2 : ");
    scanf("%d",&num2);
    for (i=1;i<=num1 && i<=num2;i++){
        if(num1%i==0 && num2%i==0)
        hcf = i;
    }
    printf("For given numbers %d , %d \n",num1,num2);
    lcm = (num1*num2)/hcf;
    printf("HCF is : %d and LCM is : %d",hcf,lcm);
    return 0;

}