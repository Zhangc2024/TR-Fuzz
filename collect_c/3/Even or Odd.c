#include<stdio.h>
int main()
{
	int a;
	printf("Enter a number: ");
	scanf("%d",&a);
	if(0==a%2)
	printf("The number is even");
	else
	printf("The number is odd");
	return 0;
}
