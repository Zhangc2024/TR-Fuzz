/*Write A program to find maximum of four numbers*/
#include<stdio.h>
#include<conio.h>
int main()
{
	int a,b,c,d,max;
	printf("Enter Four numbers");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	/*if(a>b)
	{
		if(a>c)
		{
			if(a>d)
			max=a;
			else
			max=d;
		}
		else
		{
			if(c>d)
			max=c;
			else
			max=d;
		}
	}
	else
	{
		if(b>c)
		{
			if(b>d)
			max=b;
			else
			max=d;
		}
		else
		{
			if(c>d)
			max=c;
			else
			max=d;
		}
	}*/
	max=a>b?(a>c?(a>d?a:d):(c>d?c:d)):(b>c?(b>d?b:d):(c>d?c:d));
	printf("The maximum of Four numbers is %d",max);
	getch ();
	return 0;
}
