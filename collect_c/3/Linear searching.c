//SEARCHING
/*LINEAR SEARCH*/
#include<stdio.h>
#include<conio.h>
int main()
{
	int a[10],n,i,found,item;
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
	
	//LINEAR SEARCHING
	found=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==item)
		{
			found=1;
			break;
		}
	}
	if(found==1)
	{
		printf("Found at position %d",i+1);
	}
	else
	{
		printf("Not found in the given array");
	}
	getch();
	return 0;
}
