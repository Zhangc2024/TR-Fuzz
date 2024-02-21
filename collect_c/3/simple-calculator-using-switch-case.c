#include<stdio.h>
int main(){
 int operator;
 double firstoperand,secondoperand;
 printf("enter the operation you want to perform -> ");
 scanf("%d",&operator);
 printf("enter the first operand -> ");
 scanf("%lf",&firstoperand);
 printf("enter the second operand -> ");
 scanf("%lf",&secondoperand);
double sum,sub,mult,div;
sum = firstoperand + secondoperand;
sub = firstoperand - secondoperand;
mult = firstoperand * secondoperand;
div = 
switch (operator)
{
case '+' :
    printf("%lf",sum);
    break;
case '-' :
    printf("%lf",sub);
    break;
case '*' :
    printf("%lf",mult);
    break;
case '/' :
    printf("%f", firstoperand / secondoperand;);
    break;
default:
    printf("Incorrect Operator Try again!");
}
return 0;
}