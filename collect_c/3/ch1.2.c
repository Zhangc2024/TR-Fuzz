#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ...., 30 */
main(){
    /*int fahr, celsius;*/
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * ( fahr-32 ) / 9;
//        printf("%d\t%d\n", fahr, celsius);
        printf("%8.2f\t%8.2f\n", fahr, celsius);

        fahr = fahr + step;
    }
}
