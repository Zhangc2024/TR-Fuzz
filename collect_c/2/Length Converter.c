#include <stdio.h>
 
int main()
{
  	float Millimeter, Centimeter, Meter, Kilometer;
 
 	printf("\n Please enter your value in km :  ");
  	scanf("%f", &Kilometer);
  
  	Meter = Kilometer * 1000.0;
  	Centimeter = Kilometer * 100000.0; 	
  	Millimeter = Kilometer * 1000000.0; 	
 
    printf("\n %.2f Kilometers  = %.2f Meters", Kilometer, Meter);
    printf("\n %.2f Kilometers  = %.2f Centimeters", Kilometer, Centimeter);
    printf("\n %.2f Kilometers  = %.2f Millimeters", Kilometer, Millimeter);
  
   	return 0;
