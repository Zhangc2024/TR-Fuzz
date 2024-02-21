#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n,i,j,l,m;
    scanf("%d", &n);
  	l=n*2-1;
    for(i=0;i<l;i++)
    {
        for(j=0;j<l;j++)
        {
            m=i<j?i:j;
            m=m<l-i?m:l-i-1;
            m=m<l-j-1?m:l-j-1;
            printf("%d ",n-m);
        }
        printf("\n");
    }
    return 0;
}

