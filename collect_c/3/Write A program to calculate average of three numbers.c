/*Write A program to calculate average of three numbers*/

#include<stdio.h>
#include<conio.h>

int main()
{
	int a,b,c;
	float avg;
	printf("Enter three numbers");
	scanf("%d%d%d",&a,&b,&c);
	avg=(a+b+c)/3.0;
	printf("%f",avg);
	getch();
	return 0;
}
