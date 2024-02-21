
#include<stdio.h>
int main()
{
	int n,original,r,s;
	printf("Enter A Number ");
	scanf("%d",&n);
	original=n;
	while(n!=0)
	{
		r=n%10;
		n=n/10;
		s=10*s+r;
	
	}
	if(original==s)
	printf("This is a Palindrome Number");
	else
	printf("This is not a Palindrome Number");
	return 0;
}
