#include<stdio.h>
int main()
{
	float c,f;
	printf("Enter the temperature in fahrenheit: ");
	scanf("%f",&f);
	c=((f-32)/9)*5;
	printf("The temperature in CELSIUS : %f",c);
	return 0;
}
