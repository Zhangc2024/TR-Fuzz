/*Write A Program to print remainder of two numbers.*/

#include<stdio.h>
#include<conio.h>

int main()
{
	int a,b,rem;/*Variable Declaration*/
	printf("Enter two numbers");
	scanf("%d%d",&a,&b);/*Input*/
	rem=a%b;/*Logic*/
	printf("%d",rem);/*Output*/
	getch();/*This holds the output screen on monitor*/
}
