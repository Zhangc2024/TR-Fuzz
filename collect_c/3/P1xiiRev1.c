#include<stdio.h>
int main()
{
	int a=2,b,c,d=0;
	while(a<1000)
	{
		b=a%3;
		c=a%5;
		if(b==0 || c==0)
		{
			d=d+a;
		}
		a++;
	}
	printf("The sum is : %d",d);
	return 0;
}