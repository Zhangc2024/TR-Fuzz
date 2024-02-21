/* Exercise 2-7 */

/* A function inverst(x, p, n) that returns x with the n bits 
   that begin at position p inverted, leaving others unchanged. 
*/ 

#include <stdio.h>

unsigned invert(unsigned x, int p, int n); 

int main()
{
    printf("Hello, world\n"); 
    printf("%u\n", invert(455, 5, 3)); // 511
    printf("%u\n", invert(11, 7, 4));  // 251
}

/*invert(x, p, n)*/
unsigned invert(unsigned x, int p, int n)
{
    unsigned m = (~(~0 << n)) << (p + 1 - n);
 
    return x ^ m; 
}
