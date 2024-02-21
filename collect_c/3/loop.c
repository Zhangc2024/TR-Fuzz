// program to print first ten natural numbers sum series and their total.
#include <stdio.h>
int main()
{
    int i, sum;
    i = 1;  // initialization
    sum = 0;
    while (i < 10)    // test for final 
    {
        printf("%d + ", i);
        sum += i;
        i += 2; // i=i+2;
    }

    printf("\b\b = %d", sum);
    return 0;
}