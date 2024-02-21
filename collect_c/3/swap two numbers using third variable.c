/*Write A program to swap two numbers using third variable*/

#include<stdio.h>
#include<conio.h>

int main()
{
	int a,b,c;
	printf("Enter two numbers");
	scanf("%d%d",&a,&b);
	c=a;
	a=b;
	b=c;
	printf("after swap values are%d,%d",a,b);
	getch();
	return 0;
}
