//SEARCHING
//BINARY SEARCHING
#include<stdio.h>
#include<conio.h>

#define true 1
#define false 0
int main()
{
	int a[10],n,i,found,item,low,high,mid;
	printf("Enter how many numbers");
    scanf("%d",&n);
    //ARRAY INPUT
	for(i=0,sum=0;i<n;i++)
	{
		printf("Enter Element %d: ",i+1);
		scanf("%d",&a[i]);
	}
	
	//INPUT ITEM YOU WANT TO SEARCH
	printf("Enter the element");
	scanf("%d",&item);
	
	//BINARY SEARCHING
	found false;
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==item)
		{
			found=true;
			break;
		}
		if(item>a[mid])
		{
			low=mid+1;
		}
		if(item<a[mid])
		{
			high=mid-1;
		}
	}
		//OUTPUT
		if(found==true)
		{
			printf("found at position %d",mid+1);
		}
		else
		{
			printff("Not found");
		}
	
	getch();
	return 0;
}
