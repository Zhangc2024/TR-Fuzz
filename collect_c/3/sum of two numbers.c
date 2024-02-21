/*Write A Program to print sum of two numbers.*/

#include<stdio.h>
#include<conio.h>

int main()
{
	int a,b,sum;/*Variable Declaration*/
	printf("Enter two numbers");
	scanf("%d%d",&a,&b);/*Input*/
	sum=a+b;/*Logic*/
	printf("%d",sum);/*Output*/
	getch();/*This holds the output screen on monitor*/
	return 0;
}
