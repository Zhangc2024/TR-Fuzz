/* c-examples by A.Shtanyuk */
/* max.c - the maximum element in the array*/

#include <stdio.h>

/* iteration*/
int max1(int *arr, int size)
{
	int i,max=arr[0];
	for(i=1;i<size;i++)
		if(arr[i]>max)
			max=arr[i];
	return max;
}

/* recursion */
int max2(int *arr, int size)
{
	int temp;
	if(size==1)
		return *arr;
	else
	{
		temp=max2(arr+1,size-1);
		return (*arr>temp)?*arr:temp;
	}
}


int main()
{
	int arr[10]={1,22,3,4,5,6,7,8,9,10};
	printf("max1=%d\n",max1(arr,10));
	printf("max2=%d\n",max2(arr,10));

	return 0;
}