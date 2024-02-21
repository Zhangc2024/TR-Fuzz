#include<stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float farenheit(float temp);

int main(){
    for(int fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%3d %6.1f\n", fahr, farenheit(fahr));
    return 0;
}

float farenheit(float temp){
    return (5.0 / 9.0) * (temp - 32.0);
}
