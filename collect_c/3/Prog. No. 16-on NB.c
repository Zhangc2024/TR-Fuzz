#include<stdio.h>
int main()
{
	int a,b,c=0,d,e=0,f;
	printf("Enter the number of terms ");
	scanf("%d",&b);
	for(a=2;a<=b;a=a+2)
	{
		a=a+c;
		c=a;
	}
		for(d=1;d<=b;d=d+2)
	{
		d=d+e;
		e=d;
	}
	f=e-c;
	printf("Result %d",f);
	return 0;
}
