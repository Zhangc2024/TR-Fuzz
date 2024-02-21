#include<stdio.h>
#include<math.h>
int main()
{
	int n,original,r,a=0,s=0;
	printf("Enter A Number ");
	scanf("%d",&n);
	original=n;
	while(n!=0)
	{
		n=n/10;
		a=a+1;
	}
	n=original;
	while(n!=0)
	{
		r=n%10;
		s=s+(pow(r,a));
		n=n/10;
	}
	if(original==s)
	printf("This is an armstrong number");
	else
	printf("This is not an armstrong number");
	return 0;
}
