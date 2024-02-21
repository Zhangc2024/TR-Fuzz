#include <stdio.h>
int main(){
    int num,reverse=0,remainder;
    printf("enter the integar value : ");
    scanf("%d",&num);
    printf("You have entered %d and ",num);
    while(num!=0){
        remainder = num % 10;
        reverse = reverse * 10 + remainder;
        num /=10;
    }
    printf("the reversed integar value is : %d",reverse);
    return 0;
}