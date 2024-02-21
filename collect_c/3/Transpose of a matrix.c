/*Transpose of a matrix*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	int **m,r,c,i,j;
	printf("Enter no. of rows and cols :");
	scanf("%d%d",&r,&c);
	
	//MEMORY ALLOCATION
	m=(int **)malloc(r*sizeof(int*));//CREATING ARRAY OF POINTERS
	for(i=0;i<r;i++)
	{
		m[i]=(int *)malloc(c*sizeof(int));//CREATING MATRIX
	}
	
	//MATRIX INPUT
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter element %d %d :",i+1,j+1);
			scanf("%d",&m[i][j]);
		}
	}
	
	printf("ORIGINAL MATRIX\n\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	}
	
	printf("TRANSPOSED MATRIX\n\n");
	for(i=0;i<c;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%d\t",m[j][i]);
		}
		printf("\n");
	}
	
	//MEMORY FREE
	for(i=0;i<r;i++)
	{
		free (m[i]);
	}
	free (m);
	getch();
	return 0;
}
