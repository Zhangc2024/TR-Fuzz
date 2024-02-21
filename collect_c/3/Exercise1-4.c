#include <stdio.h>

 main() {
	float fahr, celsius;
	float lower, upper, step;
	
	lower = 0; 
	upper = 300;
	step = 20;
	fahr = lower;
 	
 	printf ("Celsius\t Farenheit\n");
	while (celsius <= upper) {
		fahr = (celsius*9.0/5.0) + 32.0;
		printf("%4.0f\t %4.0f\n", celsius, fahr);
		celsius = celsius + step;
 	}
 	
 } 
