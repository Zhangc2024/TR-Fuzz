/*Write A Program to print remainder of two numbers without using % operator.*/

#include<stdio.h>
#include<conio.h>

int main()
{
	int n,d,rem;
	printf("Enter two numbers");
	scanf("%d%d",&n,&d);
	rem=n-(d*(n/d));
	printf("%d",rem);
	getch();
	return 0;
}
