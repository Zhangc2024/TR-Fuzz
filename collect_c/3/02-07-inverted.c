/**
    return x with the n bits that begin at position p inverted
**/

#include <stdio.h>
unsigned inverted(unsigned x, int p, int n){
    return ~( x & ~(~0 << n) << (p - n) ) & (x |  ~(~0 << n) << (p - n));
}
unsigned inverted2(unsigned x, int p, int n)
{
    return ~(~0 << n) << (p - n) ^ x;
}
/**
    1111 1101 1111 1111
    1111 0010 1111 1111
    p = 12
    n = 4
**/

main(){
    unsigned m;
    m = inverted(65023, 12, 4);
    printf("%x\n", m);
    m = inverted2(65023, 12, 4);
    printf("%x\n", m);
}
