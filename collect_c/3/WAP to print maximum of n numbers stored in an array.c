/*WAP to print maximum of n numbers stored in an array*/
#include<stdio.h>
#incdlue<conio.h>
int main()
{
	int a[10],i,n,max,max_pos;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	//Array Input
	for(i=0,sum=0;i<n;i++)
	{
		printf("Enter Element %d: ",i+1);
		scanf("%d",&a[i]);
	}
	//CALCULATING MAX
	max=a[0];
	pos=0;
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
			pos=i;
		}
	}
	//OUTPUT
	printf("max=%d\nAt position %d",max,max_pos);
	getch();
	return 0;
}
