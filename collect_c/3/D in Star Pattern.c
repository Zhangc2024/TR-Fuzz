/* 
      *****
       *  * 
       *  *
       *  *
      *****  
              */
#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,n;
	printf("Enter the no. of rows");
	scanf("%d",&n);
	for(i=1;i<=n;i++)  
    {  
        for(j=1;j<=n;j++)  
        {  
            if(i==1||i==n||j==2||j==n)  
            {  
            printf("*");  
            }  
            else  
            printf(" ");  
        }  
        printf("\n");  
    }  
}              
