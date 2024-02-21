#include<stdio.h>
void main()
{
	int inp,kg,g;
	printf("Enter the quantity in Grams ");
	scanf("%d",&inp);
	kg=inp/1000;
	g=inp%1000;
	printf("You entered : %d Kgs. and %d Grams.",kg,g);
}
