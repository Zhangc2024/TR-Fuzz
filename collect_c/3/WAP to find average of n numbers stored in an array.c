/*WAP to find average of n numbers stored in an array*/
#include<stdio.h>
#include<conio.h>
int main()
{
	int a[10],n,i,sum;
	float avg;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	//Array Input
	for(i=0,sum=0;i<n;i++)
	{
		printf("Enter Element %d: ",i+1);
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	//AVERAGE 
	avg=(float)sum/n;
	printf("sum is %d for %d elements and average is %.2f",sum,n,avg);
	getch();
	return 0;
}
