/*Write A Program to print product of two numbers.*/

#include<stdio.h>
#include<conio.h>

int main()
{
	int a,b,prd;/*Variable Declaration*/
	printf("Enter two numbers");
	scanf("%d%d",&a,&b);/*Input*/
	prd=a*b;/*Logic*/
	printf("%d",prd);/*Output*/
	getch();/*This holds the output screen on monitor*/
}
