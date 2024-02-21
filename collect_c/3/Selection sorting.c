//SELECTION SORTING
#include<stdio.h>
#include<conio.h>
int main()
{
	int a[20],n,i,j,t;
	printf("Enter how many elements:")
	scanf("%d",&n);
	//ARRAY INPUT
	for(i=0;i<n;i++)
	{
		printf("Enter element %d:",i+1);
		scanf("%d",&a[i]);
	}
	//UNSORTED ARRAY
	printf("Array before sorting");
	for(i=0;i<n;i++)
	{
		printf("%d\t",&a[i]);
	}
	//SELECTION SORTING
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	//SORTED ARRAY
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	getch();
	return 0;
}
