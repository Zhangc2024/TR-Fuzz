/*
    *
    *
    *
    *
    *****
             */
#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,n;
	printf("Enter The No. Of Rows");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(j==1||i==n)
				printf("*");
			printf(" ");		
		}
		printf("\n");
	}
	getch();
	return 0;
}             
