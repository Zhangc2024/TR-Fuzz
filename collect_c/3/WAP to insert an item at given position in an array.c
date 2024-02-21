/*WAP to insert an item at given position in an array*/
// OR OR OR OR OR OR
/*WAP to insert an item in an unsorted array*/
#include<stdio.h>
#include<conio.h>
int main()
{
	int a[20],i,pos,n,item;
    printf("Enter how many numbers");
    scanf("%d",&n);
    //ARRAY INPUT
	for(i=0,sum=0;i<n;i++)
	{
		printf("Enter Element %d: ",i+1);
		scanf("%d",&a[i]);
	}
	
	printf("Enter item to  be inserted:");
	scanf("%d",&item);
	
	printf("Enter position:");
	scanf("%d",pos);
	pos--;
	
	//SHIFTING
	for(i=n-1;i>pos;i--)
	{
		a[i+1]=a[i];
	}
	
	//INSERT
	a[pos]=item;
	n++;
	
	//OUTPUT
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	getch();
	return 0;
}
