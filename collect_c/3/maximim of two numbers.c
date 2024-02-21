#include<stdio.h>
#include<conio.h>

int main()
{
	int a,b,max;
	printf("Enter two numbers");
	scanf("%d%d",&a,&b);
	if(a>b)
	 max=a;
	else
	 max=b;
	printf("maximum of %d and %d is %d",a,b,max);
	getch();
	return 0;
	}
