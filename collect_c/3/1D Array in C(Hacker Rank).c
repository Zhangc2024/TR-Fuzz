#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n,sum;
    scanf("%d",&n);
    int *a;
    a=(int*)malloc(n*sizeof(int));
    sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",(a+i));
        sum=sum+*(a+i);
    }
    printf("%d",sum);    
    return 0;
}

