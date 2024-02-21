#include<stdio.h>
int main()
{
	int a,b,c;
	printf("Enter The Value of 'A' : ");
	scanf("%d",&a);
	printf("Enter The Value of 'B' : ");
	scanf("%d",&b);
	c=b;
	b=a;
	a=c;
	printf("A=%d B=%d",a,b);
	return 0;
}
