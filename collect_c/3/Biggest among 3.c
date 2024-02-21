#include<stdio.h>
int main()
{
	int a,b,c,m;
	printf("Enter three numbers : ");
	scanf("%d%d%d",&a,&b,&c);
	if((a>b)&&(a>c))
	m=a;
	else if((b>a)&&(b>c))
	m=b;
	else
	m=c;
	printf("The Biggest is %d",m);
	return 0;
}
