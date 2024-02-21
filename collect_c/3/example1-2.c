#include <stdio.h>

/* Print Fahrenheit-Celsius table 
 *  for fahr = 0,  ..., 300 
 */

int main()
{

  int fahr, celsius;
  int lower, upper, step;

  lower = 0;     /* lower limit of temperature table */
  upper = 220;   /* upper limit */
  step = 5;     /* step size */

  fahr = lower;
  printf("Fahrenheit \t Celsius\n");
  printf("---------------------------\n");
  while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%3d\t\t%6d\n", fahr, celsius);
    fahr = fahr + step;
  }
  return 0;
}

  
