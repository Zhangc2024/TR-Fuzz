/* Example in section 1.2 
   Final version of the example using floats and with answer to 
   Exercise 1-3
*/

#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ... , 300 */
main ()
{
    float fahr, celsius; 
    int lower, upper, step; 

    lower = 0; 
    upper = 300; 
    step = 20; 

    printf ("Fahrenheit\tCelsius\n"); // heading of the table

    fahr = lower; 
    while (fahr <= upper) {
	celsius = (fahr - 32.0) * (5.0 / 9.0); 
	// two tabs in the line below to line up with the 
	// heading. 
	printf("%0.0f\t\t%6.1f\n", fahr, celsius);
	fahr = fahr + step; 
    }
}
