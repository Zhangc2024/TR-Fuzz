# include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

/**
 * print Farenheit-Celsius table
 * for fahr = 0, 20, ..., 300
 **/

int main()
{
  /* print header */
  printf("%4s | %6s\n", "fahr", "cels");
  printf("-------------\n");

  int fahr;
  for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    printf("%4d | %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
