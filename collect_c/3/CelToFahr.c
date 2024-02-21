/* Exercise 1-4 */

#include <stdio.h>

/* print Celsius-Fahrenheit table
   for celsius = -20, -10, ... , 150
*/
int main()
{
    float celsius, fahr; 
    int lower, upper, step; 

    lower = -20; 
    upper = 150; 
    step = 10; 

    printf("Celsius\tFahrenheit\n"); 

    celsius = lower; 
    while (celsius <= upper) {
	fahr = celsius * (9.0 / 5.0) + 32; 
	printf("%0.0f\t%6.1f\n", celsius, fahr); 
	celsius = celsius + step; 
    }
}
