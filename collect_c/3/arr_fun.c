/* c-examples by A.Shtanyuk */
/* arr_fun.c - the sum of the array elements */


#include <stdio.h>

/* one-dimensional array*/
int summa(int *arr,int N)
{
	int i,s=0;
	for(i=0;i<N;i++)
		s+=arr[i];
	return s;
}

/* two-dimensional array */
int summa2D(int (*arr)[5],int N)
{
	int s=0,i,j;
	for(i=0;i<N;i++)
		for(j=0;j<5;j++)
			s+=arr[i][j];
	return s;
}

/* one-dimensional array again */
int summa2D_1(int *arr,int N)
{
	int i,s=0;
	for(i=0;i<N;i++)
			s+=arr[i];
	return s;
}

int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int arr2D[3][5]={{1,2,3,4,5},{6,7,8,9,10},{1,2,3,4,5}};
	
	/* a pointer to an array*/
	int (*p)[5]=(int(*)[5])arr;

	printf("Sum=%d\n",summa(arr,10));
	printf("Sum2D=%d\n",summa2D(arr2D,3));
	printf("Sum2D=%d\n",summa2D_1(&arr2D[0][0],15));
    printf("Sum2D=%d\n",summa2D(p,2));
	return 0;
}