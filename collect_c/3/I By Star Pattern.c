/*
	*****
	  *
	  *
	  *
	*****
			*/
#include<stdio.h>
#include<conio.h>
int main()
{
	int n,i,j;  
    printf("Enter the number of rows");  
    scanf("%d",&n);  
    for(i=1;i<=n;i++)  
    {  
        for(j=1;j<=n;j++)  
        {  
            if(i==1||i==n||j==n/2)  
            {  
            printf("*");  
            }  
            else  
            printf(" ");  
        }  
        printf("\n");  
    }  
    getch(); 
    return 0;  
}				
