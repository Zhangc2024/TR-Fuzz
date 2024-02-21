/*WAP to left rotat elements of an array*/
#include<stdio.h>
#include<conio.h>
int main()
{
	int a[10],n,i,t,j;
	printf("Enter how many numbers:");
	scanf("%d",&n);
	
	//ARRAY INPUT
	for(i=0,sum=0;i<n;i++)
	{
		printf("Enter Element %d: ",i+1);
		scanf("%d",&a[i]);
	}
	
	//LEFT ROTATE
	t=a[0];
	//SHIFTING
	for(i=0;i<n-1;i++)
	{
		a[i]=a[i+1];
	}
	a[n-1]=t;
	
	//OUTPUT
	
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	getch();
	return 0;
}
