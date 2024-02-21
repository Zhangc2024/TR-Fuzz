/*
  		4 4 4 4 4 4 4
  		4 3 3 3 3 3 4
  		4 3 2 2 2 3 4
  		4 3 2 1 2 3 4
		4 3 2 2 2 3 4
		4 3 3 3 3 3 4
		4 4 4 4 4 4 4			*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    printf("Enter No. of Rows");
    scanf("%d", &n);
  	int len=n*2-1;
      int i,j;
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
        {
            int min=i<j?i:j;
            min=min<len-i?min:len-i-1;
            min=min<len-j-1?min:len-j-1;
            printf("%d ",n-min);
        }
        printf("\n");
    }
    return 0;
}

