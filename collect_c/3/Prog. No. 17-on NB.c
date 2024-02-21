#include<stdio.h>
int main()
{
	float a,b,c,d;
	c=1;
	printf("Enter a number ");
	scanf("%f",&a);
	for(b=1;b<=a;b++)
	{
		c=c*b;
		d=d+(1/c);
	}
	printf("Result= %f",d);
	return 0;
}
