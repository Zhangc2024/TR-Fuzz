#include <stdio.h>

#define LOWER 0   /** 表的下限 **/
#define UPPER 300 /** 表的上限 **/
#define STEP 20   /** 步进值   **/


/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ...., 300 */
main(){
    float fahr, celsius;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr+STEP) {
        printf("%8.2f\t%8.2f\n", fahr,  5 * ( fahr-32 ) / 9);

//        fahr = fahr + STEP;
    }
}
