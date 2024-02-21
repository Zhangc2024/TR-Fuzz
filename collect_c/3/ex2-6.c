#include <stdio.h>
#include <limits.h>

/*
 * Exercise 2-6. A function that returns x with the n bits that begin at position p
 * set to the rightmost n bits of y leaving the other bits unchanged.
 *
 */

int setbits(int x, int p, int n, int y);

int main()
{
    
    printf("setbits return value  is %d\n", setbits(1024, 4, 2, 4021)); //should return 1032

    return 0; //return SUCCESS
}

int setbits(int x, int p, int n, int y)
{
    // for e.g.
    // p = 3, n = 3
    // x = zzzz100z
    // y = zzzzz111
    // return zzzz111z

    return  (x & ~(0xFFFFFFFF >> (31 - p) & 0xFFFFFFFF << (p - n + 1))) |
            (y & ~(0xFFFFFFFF << n)) << (p - n + 1);
}
