#include<stdio.h>
int main()
{
	int a,b,c;
	c=1;
	printf("Enter a number ");
	scanf("%d",&a);
	for(b=1;b<=a;b++)
	{
		c=c*b;
	}
	printf("%d",c);
	return 0;
}
