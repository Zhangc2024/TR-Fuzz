#include<stdio.h>
int main()
{
	int a=1,n,s=0;
	printf("Enter a number ");
	scanf("%d",&n);
	while(n/a!=1)
	{
		if(n%a==0)
		{
			s=s+a;
		}
		a++;
	}
	if(s==n)
	printf("This is a perfect number");
	else
	printf("This is not a perfect number");
	return 0;
}
