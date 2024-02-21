#include<stdio.h>
#include<math.h>
int main(){
    int num,first,result = 0,remain,order=0;
    printf("enter the value of num :");
    scanf("%d",&num);
    first = num;
    while(num!=0)  
   {  
       num/=10;  
       order++;  
   }  
   num = first;
    while(num != 0){
        remain = num % 10;
        result += pow(remain, order);
        num/=10;
    }
    if (result == first){
        printf("Your given number(%d) is a armstrong number ",first);
    }
    else {
        printf("Your given number(%d) is not a armstrong number ",first);
    }
    return 0;
}