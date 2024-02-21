#include<stdio.h>
#define swap(t,x,y) t = x, x = y, y = t

main() {
	
	float x, y, t;
	
	printf("Enter value x: ");
	scanf("%f", &x);
	
	printf("Enter value y: ");
	scanf("%f", &y);
	
	swap(t, x, y);
	printf("\nSwaped values\n");
	printf("X value: %g\n", x);
	printf("Y value: %g\n", y);
	
	
}
