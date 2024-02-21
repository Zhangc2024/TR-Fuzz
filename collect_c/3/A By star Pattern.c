/*
    	   *
    	  * *
         *****
	*     *
       *       *
*/
#include<stdio.h>
#include<conio.h> 
int main()
{
	int n,i,j,k;
	printf("Enter No. of Rows");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(k=1;k<=n-i;k++)
		printf(" ");
		for(j=1;j<=2*i-1;j++)
		{
			if(j==1||j==2*i-1||i==n/2+1)
			printf("*");
			else
			printf(" ");
		}
		printf("\n");
	}
}                    
