/*Write A Program to print difference of two numbers.*/

#include<stdio.h>
#include<conio.h>

int main()
{
	int a,b,diff;/*Variable Declaration*/
	printf("Enter two numbers");
	scanf("%d%d",&a,&b);/*Input*/
	diff=a-b;/*Logic*/
	printf("%d",diff);/*Output*/
	getch();/*This holds the output screen on monitor*/
}
