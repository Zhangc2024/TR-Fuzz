/*Write A program to swap two numbers without using third variable*/

#include<stdio.h>
#include<conio.h>

int main()
{
	int a,b;
	printf("Enter two numbers");
	scanf("%d%d",&a,&b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("after swap values are%d,%d",a,b);
	getch();
	return 0;
}
