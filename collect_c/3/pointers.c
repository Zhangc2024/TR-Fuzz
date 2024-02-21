#include<stdio.h>
 
int main()
{
    int sum =1,k=9;
    do {
        k = k-1;
        sum = 2*sum;

    } while (k>0);
    printf("%d",sum);
    return 0;
}