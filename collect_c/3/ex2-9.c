#include <stdio.h>

/* Exercise 2-9. faster version of bitcount */

int bitcount(unsigned x);

int main()
{
    printf("Number of one's in 4021 is %d\n", bitcount(4021));

    return 0; //return SUCCESS
}

int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x -1))
    {
        b++;
    }

    return b;
}
