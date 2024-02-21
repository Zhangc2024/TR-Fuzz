#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dividend = 20;
    int divisor = 5;
    int quotient;

    if( divisor == 0)   {
        print(stderr, "Divison by zero! Exiting...\n");
        exit(EXIT_FAILURE);
    }
    quotient = dividend / divisor;
    
}