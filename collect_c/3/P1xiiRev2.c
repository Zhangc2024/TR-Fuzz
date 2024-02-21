#include<stdio.h>
int main()
{
	int b=0,c=0,e=0,x=0,sum3=0,sum5=0,sum15=0;
	while(b<1000)
	{
		b=b+3;
		sum3=sum3+b;
	}
	while(c<1000)
	{
		c=c+5;
		sum5=sum5+c;
	}
	while(e<1000)
	{
		e=e+15;
		sum15=sum15+e;
	}
	x=sum3+sum5-sum15;
	printf("The sum is : %d",x);
	return 0;
}