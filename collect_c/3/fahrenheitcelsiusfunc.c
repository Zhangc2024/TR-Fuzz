#include <stdio.h>

#define LOWER 0.0       /* lower limit of table */
#define UPPER 300.0     /* upper limit */
#define STEP 20.0       /* step size */

float convertToC(float f);

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
main()
{
    float fahr;

    printf("Temperature Conversion Table:\n");
    printf("Fahrenheit\tCelsius\n");
    printf("----------------------------\n");
    
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%6.1f\t\t%6.1f\n", fahr, convertToC(fahr));

    return 0;
}

/* function to convert the quantity f from celsius
 * to fahrenheit */
float convertToC(float f)
{
    return (5.0/9.0) * (f-32.0);
}
