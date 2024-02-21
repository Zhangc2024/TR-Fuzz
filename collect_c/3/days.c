#include<stdio.h>

int main(){
    int n;
    printf("enter the number of days");
    scanf("%d",&n);
    int year=n/365;
    int ad=n%365;
    int month=ad/30;
    int days=ad%30;
    printf("%d   %d   %d",year,month,days);
    return 0;
}