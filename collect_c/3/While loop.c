#include<stdio.h>
int main()
{
	int n,r,s,a=0;
	printf("Enter A Number");
	scanf("%d",&n);
	while(n!=0)
	{
		r=n%10;
		n=n/10;
		s=10*s+r;
		a++;
	}
	printf("%d  ",s);
	printf("Number of digits %d",a);
	return 0;
}
