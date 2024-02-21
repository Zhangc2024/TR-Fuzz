/*WAP to check wether a given matrix is diagonal or not*/
#include<stdio.h>
#include<conio.h>
int main()
{
	int m[10][10],r,c,i,j;
	printf("Enter no. of rows and cols");
	scanf("%d%d",&r,&c);
	//MATRIX INPUT
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter element %d %d",i+1,j+1);
			scanf("%d",&m[i][j]);
		}
	}
	if(r==c)
	{
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(i==j&&m[i][j]==0 || i!=j&&m[i][j]!=0)
				{
					printf("Not a Diagonal matrix");
					getch();
					exit 0;
				}
			}
		}
		printf("It is diagonal matrix");
	}
	else
	{
		printf("Not a Diagonal matrix");
	}
	getch();
	return 0;
}

