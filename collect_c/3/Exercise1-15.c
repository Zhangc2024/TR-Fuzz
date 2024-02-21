#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int con (float fahr);

 main() {
	
	float fahr, celsius;
 	
 	printf ("Farenheit\tCelsius \n");
	for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
		printf("%4.0f\t\t %4d\n",  fahr, con(fahr));
		
 	}
 	 
 
 int con (float fahr) {
 
	float cel;
	cel = (5.0/9.0) * (fahr-32.0);

 	return cel;
 	
 }
