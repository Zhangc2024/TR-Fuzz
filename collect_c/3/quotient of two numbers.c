/*Write A Program to print quotient of two numbers.*/

#include<stdio.h>
#include<conio.h>

int main()
{
	int a,b,qot;/*Variable Declaration*/
	printf("Enter two numbers");
	scanf("%d%d",&a,&b);/*Input*/
	qot=a/b;/*Logic*/
	printf("%d",qot);/*Output*/
	getch();/*This holds the output screen on monitor*/
}
