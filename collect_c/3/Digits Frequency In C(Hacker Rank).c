#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char str[1000000];
    scanf("%s",str);
    int i,count,j,k;
    i=j=k=count=0;
    char a[10]="0123456789";
    int len=strlen(str);
    int b[10]={0};
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
        {
            if(str[j]==a[k])
            {
                count++;
            }
        }
        b[k]=count;
        count=0;
        k++;
    }
    for(i=0;i<10;i++)
    {
        printf("%d ",b[i]);
    }
    return 0;
}

