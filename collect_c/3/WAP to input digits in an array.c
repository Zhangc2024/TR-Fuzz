//ARRAY
/*WAP to input digits in an array*/
#include<stdio.h>
#include<conio.h>
int main()
{
	int a[50],n,i;  //ARRAY DECLARATION
	printf("Enter how many Elements: ");
	scanf("%d",&n);
	//ARRAY INPUT
	for(i=0;i<n;i++)
	{
		printf("Enter Element %d: ",i+1);
		scanf("%d",&a[i]);
	}
	//ARRAY OUTPUT
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	getch();
	return 0;
}
