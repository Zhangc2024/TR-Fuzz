#include<stdio.h>
int main()
{
	int n,r,s;
	printf("Enter A Number");
	scanf("%d",&n);
	while(n!=0)
	{
		r=n%10;
		s=s+r;
		n=n/10;
	}
	printf("Sum of the digits are = %d",s);
	return 0;
}
