/*Row wise Sorting*/
#include<stdio.h>
#include<conio.h>
int main()
{
	int m[10][10],r,c,i,j,k,t;
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
	
	printf("MATRIX BEFORE SORTING\n\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	}
	
	//ROW-WISE SORTING(SELECTION SORT)
	for(k=0;k<r;k++)
	{
		for(i=0;i<c;i++)
		{
			for (j=i+1;j<c;j++)
			{
				if(m[k][i]>m[k][j])
				{
					t=m[k][i];
					m[k][i]=m[k][j];
					m[k][j]=t;
				}
			}
		}
	}
	printf("MATRIX AFTER SORTING\n\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	}
	getch();
	return 0;
}
