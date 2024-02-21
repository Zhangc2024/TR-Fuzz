/*Write A program to calculate average of two numbers*/

#include<stdio.h>
#include<conio.h>

int main()
{
	int a,b;
	float avg;
	printf("Enter two numbers");
	scanf("%d%d",&a,&b);
	avg=(a+b)/2.0;
	printf("%f",avg);
	getch();
}
