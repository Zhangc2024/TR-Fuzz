/*WAUDF to sort a givenlist of N integer numbers using selection sort techniqe*/
#include<stdio.h>
#include<conio.h>
void sort(int[],int);

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
	/*Selection Sort
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
	}*/
	printf("size of arraya=%d\n",sizeof(a));
	sort(a,n);
	/*Output*/
	printf("Sorted Array:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	getch();
	return 0;
}
void sort(int b[],int n)
{
    int i,j,t;
	printf("size of b=%d\n",sizeof(b));
	/*Selection Sort*/
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(b[i]>b[j])
			{
				t=b[i];
                b[i]=b[j];
                b[j]=t;
			}
		}
	}
}
