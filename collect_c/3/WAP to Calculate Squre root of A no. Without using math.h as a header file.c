/*WAP to Calculate Squre root of A no. Without using math.h as a header file*/
#include <stdio.h>
#include <conio.h>

int main()
{
	float i,n;
	
	printf("Enter a number \n");
	scanf(" %f", &n);
	for(i=0.01;i*i<n;i+=0.01);
		printf("\n%.3f", i);
	return 0;
}
