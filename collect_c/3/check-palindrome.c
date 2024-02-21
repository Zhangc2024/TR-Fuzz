#include <stdio.h>
int main(){
    int num,reverse=0,remainder;
    printf("enter the integar value : ");
    scanf("%d",&num);
    int number = num;
    printf("You have entered %d and ",num);
    while(num!=0){
        remainder = num % 10;
        reverse = reverse * 10 + remainder;
        num /=10;
    }
    (reverse == number) ? printf("the number is palindrome number") : printf("the number is not palindrome");
    return 0;
}