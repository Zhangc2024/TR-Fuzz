/*Write A program to swap three numbers using fourth variable*/

#include<stdio.h>
#include<conio.h>

int main()
{
	int a,b,c,d;
	printf("Enter three numbers");
	scanf("%d%d%d",&a,&b,&c);
	d=a;
	a=b;
	b=c;
	c=d;
	printf("after swap values are%d,%d,%d",a,b,c);
	getch();
	return 0;
}
