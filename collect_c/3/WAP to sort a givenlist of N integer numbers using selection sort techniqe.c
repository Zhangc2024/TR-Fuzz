/*WAP to sort a givenlist of N integer numbers using selection sort techniqe*/
#include<stdio.h>
#include<conio.h>
int main()
{
	int a[10],n,i,j,t;
	printf("Enter How Many NO.");
	scanf("%d",&n);
	/*Input Array*/
	for(i=0;i<n;i++)
	{
		printf("Enter element %d:",i+1);
		scanf("%d",&a[i]);
	}
	/*Selection Sort*/
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
	/*Output*/
	printf("Sorted Array:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	getch();
	return 0;
}
