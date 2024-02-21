/* setbits: set n bits of x at position p with bits of y */
#include <stdio.h>
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return x & ~(~(~0 << n) << (p-n))  |
          (y & ~(~0 << 0)) << (p-n);
}
/**
2810 : 1010 1111 1010
2720 : 1010 1010 0000

2570 : 1010 0000 1010
*/
main(){
    unsigned m;
    m = setbits(2810,8,4,2720);
    printf("%d",m);
}
