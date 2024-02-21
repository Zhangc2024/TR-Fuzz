#include<stdio.h>

int main(){
    int n,rem,result=0,m=1;
    printf("enter the number");
    scanf("%d",&n);
    while(n>0){
        rem=n%10;
        result=result+(rem*m);
        n=n/10;
        m=m*2;
    }
    printf("decimal number=%d",result);
    return 0;
}