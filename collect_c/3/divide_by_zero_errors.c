#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dividend = 20;
    int divisor = 0;
    int quotient;

    if(divisor == 0)
    {
        fprintf(stderr, "Division by zero! Existing...\n");
        exit(-1);
    }
    quotient = dividend / divisor;
    fprintf(stderr, "Value of quotient: %d\n", quotient);

    exit(0);
}
