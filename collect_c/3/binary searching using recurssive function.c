//BINARY SEARCH USING RECURSSION(ARRAY MUST BE SORTED)
#include<stdio.h>
#include<conio.h>
//FUNCTION DECLARATION
int binary_search(int[],int,int,int);
int main()
{
	int a[10],n,i,pos,item;
	printf("Enter how many numbers");
    scanf("%d",&n);
    printf("Enter element in ascending order\n\n");
    //ARRAY INPUT
	for(i=0,sum=0;i<n;i++)
	{
		printf("Enter Element %d: ",i+1);
		scanf("%d",&a[i]);
	}
	
	//INPUT ITEM YOU WANT TO SEARCH
	printf("Enter the element");
	scanf("%d",&item);
	
	//FUNCTION CALL
	pos=binary_search(a,o,n-1,item);
	
	if(pos==-1)
	{
		printf("Not found");
	}
	else
	{
		printf("Found at position %d",pos);
	}
	getch();
	return 0;
}
int binary_search(int a[],int low,int high,int item)
{
	int mid;
	if(low>high)
	{
		return -1;
	}
	mid=(low+high)/2;
	if(a[mid]==item)
	{
		return mid;
	}
	else if(item>a[mid])
	{
		return binary_search(a,mid+1,high,item);
	}
	else
	{
		return binary_search(a,low,mid-1,item);
	}
}
