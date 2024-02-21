//Reverse A given float array
#include<stdio.h>
#include<conio.h>
void reverse(float[],int);  //FUNCTION DECLARATION
int main()
{
	float a[10];
	int n,i;
	printf("Enter the no. of elements:");
	scanf("%d",&n);
	//INPUT ARRAY
	for(i=0;i<n;i++)
	{
		printf("Enter element %d:",i+1);
		scanf("%f",&a[i]);
	}
	printf("Size of a=%d\n",sizeof(a));
	printf("Address of a=%p\n",a);
	
	reverse(a,n);  //FUNCTION CALL
	printf("Reverse:\n\n\n\n");
	for(i=0;i<n;i++)
	{
		printf("%g\t",a[i]);  //%g=genius
	}
	getch();
}
void reverse(float b[],int n)  //FUNCTION DEFINATION
{
	int i,j;
	float t;
	printf("Size of b=%d\n",sizeof(b));
	printf("Address of b=%p\n",b);
	for(i=0,j=n-1;i<j;i++,j--)
	{
		t=b[i];
		b[i]=b[j];
		b[j]=t;
	}
}
