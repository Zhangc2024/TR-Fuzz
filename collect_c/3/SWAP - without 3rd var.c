#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter value for A : ");
	scanf("%d",&a);
	printf("Enter value for B : ");
	scanf("%d",&b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("A = %d",a);
	printf("\nB = %d",b);
	return 0;
}
