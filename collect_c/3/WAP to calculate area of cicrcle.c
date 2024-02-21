/*WAP to calculate radius of cicrcle*/

// #include<stdio.h>
// #include<conio.h>
// #define pi=3.14
// int main()
// {
// 	float r,area;
// 	printf("Enter the radius of circle");
// 	scanf("%f",&r);
// 	area=(3.142857)*(r*r);
// 	printf("%f",area);
// 	printf("The area of given circle with radius %f is %.2f",r,area);
// 	getch();
// 	return 0;
//}



#include<stdio.h>
#include<conio.h>
#define PI (3.141592653589793)
int main()
{
	float r,area;
	printf("Enter the radius of circle:	");
	scanf("%f",&r);
	area=(PI)*(r*r);
	printf("%f\n",area);
	printf("The area of given circle with radius %f is %.2f\n\n",r,area);
	getch();
	return 0;
}
