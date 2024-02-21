/*
    Structs

    Structs in C allow you to group together variables that can be referenced as a whole. A struct is also a new type!
    So, when you create a struct, you create a type.

    Note: in the printf statement on line 29, we use the float format specifier to print the variables, as well as
    specify how many digits should be printed. For the weight, 2 places after the decimal. For the gallons, 1 place.
*/

#include <stdio.h>

/* Make our struct, a new type called car */
struct car {
    float weight;
    float currentFuel;
};

int main(void)
{
    /* now we create an instance of car */
    struct car myCar;

    /* here we use the dot operator to access the fields in the struct */
    myCar.weight = 1000;        /* it weighs 1000 lbs */
    myCar.currentFuel = 15.6;   /* it has 15.6 gallons of gas left */

    /* print the details of our car */
    printf("Our car weighs %.2f lbs and has %.1f gallons of gas left.", myCar.weight, myCar.currentFuel);

    return 0;
}