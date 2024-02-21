#include <stdio.h>
/*
 *
 * Exercise 2-7. invert(x, p, n) that returns x with the n bits that begin at position p
 * inverted, leaving others unchanged.
 *
 */

int invert(int x, int p, int n);

int main()
{
    printf("invert(1024, 4, 2) is %d\n", invert(1024, 4, 2)); 

    return 0; //return SUCCESS
}

int invert(int x, int p, int n)
{
    //zzzz101z
    //return zzzz010z

    return  (~x | //zizizizi010zi
            ~(0xFFFFFFFF >> (31 - p) & 0xFFFFFFFF << (p - n + 1))) & // 11110001
            (x | (0xFFFFFFFF >> (31 - p) & 0xFFFFFFFF << (p - n + 1)))
            ;
}

