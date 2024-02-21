/*Write A program to find maximum of three numbers*/
#include<stdio.h>
#include<conio.h>

int main()
{
	int a,b,c,max;
	printf("Enter Three numbers");
	scanf("%d%d%d",&a,&b,&c);
	if(a>b)
	{
		if(a>c)
		max=a;
		else
		max=c;
	}
	else
	{
		if(b>c)
		max=b;
		else
		max=c;
	}
	printf("The maximum of numbers is %d",max);
	getch ();
	return 0;
}
