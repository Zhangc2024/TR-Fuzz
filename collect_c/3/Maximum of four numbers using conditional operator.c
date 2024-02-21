/*Write A program to find maximum of four numbers using conditional operator*/
#include<stdio.h>
#include<conio.h>
int main()
{
	int a,b,c,d,max;
	printf("Enter Four numbers");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	max=a>b?(a>c?(a>d?a:d):(c>d?c:d)):(b>c?(b>d?b:d):(c>d?c:d));
	printf("The maximum of Four Numbers is %d",max);
	getch ();
	return 0;
}
