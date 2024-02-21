#include<stdio.h>
int main()
{
	float a,b,c=2,d=0;
	printf("Enter a number ");
	scanf("%f",&a);
	for(b=1.0;b<=a;b++)
	{
		d=d+(b/c);
		c=c+1.0;
	}
	printf("Result %f",d);
	return 0;
}
