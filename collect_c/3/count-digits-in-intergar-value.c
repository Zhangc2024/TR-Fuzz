#include <stdio.h>
int main(){
    long long intnum;
    int digits=0;
    printf("enter the long long double value : ");
    scanf("%lld",&intnum);
    printf("Total digits count in %lld",intnum);
    do{
      intnum/=10;
      digits++;
    }while (intnum!=0);
    printf(" is : %d",digits);
    return 0;
}