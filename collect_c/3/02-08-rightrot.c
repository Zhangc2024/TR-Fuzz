/**
    return the value of the integer x rotated to the right by n bit positions
    i.e.
    12345 rotate 2 get 45123
**/

#include <stdio.h>

unsigned rightrot(unsigned x, int n)
{
    int wordlength(void);
    int rbit;

    while (n-- > 0){
        rbit = (x & 1) << (wordlength() - 1);
        x = x >> 1;
        x = x | rbit;
    }
    return x;
}

unsigned rightrot2(unsigned x, int n)
{
    if  (( n = n % wordlength()) > 0)
    {
        return x >> n | (x & ~(~0 << n)) << (wordlength() -n);
    }
}

int wordlength(void)
{
    int i;
    unsigned v = (unsigned) ~0;
    for (i = 1; (v = v >> 1) > 0; i++)
        ;
    return i;
}

/**
    11110000
    4
**/
main()
{
    int m;
    m = rightrot2(255,36);
    printf ("%x\n", 255);
    printf ("%x\n", m);
}
