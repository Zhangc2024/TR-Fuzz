/*Complete sorting*/
#include<stdio.h>
#include<conio.h>
void sort(int [][10],int,int);
int main()
{
	int m[10][10],r,c,i,j;
	printf("Enter no. of rows and cols :");
	scanf("%d%d",&r,&c);
	//MATRIX INPUT
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter element %d %d :",i+1,j+1);
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
	
	sort(m,r,c);
	
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
void sort(int m[][10],int r,int c)
{
	int i,j,k,l,t;
	//COMPLETE SORT
	for(i=0;i<r;i++)
	  for(j=0;j<c;j++)
	    for(k=i;k<r;k++)
	      for(l=0;l<c;l++)
				{
					if(i==k&&l<=j)
					  continue;
				  if(m[i][j]>m[k][l])
				  {
				  	t=m[i][j];
				  	m[i][j]=m[k][l];
				  	m[k][l]=t;
					}
			  }
				 
}

