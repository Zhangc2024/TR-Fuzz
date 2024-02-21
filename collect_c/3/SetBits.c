/* Exercise 2-6 */

/* a function setbits(x, p, n, y) that returns x with the n bits
   that begin at position p set to the rightmost n bits of y, 
   leaving the other bits unchanged. 

   Note that if n > p + 1, the behaviour is undefined. 
   See
   http://stackoverflow.com/questions/4945703/left-shifting-with-a-negative-shift-count
*/

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n); 
unsigned setbits(unsigned x, int p, int n, unsigned y); 

int main()
{
    printf("Hello, world\n"); 
    printf("299:\t%d\n", getbits(299, 4, 3)); 
    printf("315:\t%d\n", getbits(315, 4, 3));
    printf("2:\t%d\n", getbits(2, 4, 3));
    
    printf("259, 4, 3, 23: %u \n", setbits(259, 4, 3, 23)); // 287
    printf("8, 2, 5, 31: %u\n", setbits(8, 2, 5, 31)); // undefined
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n); 
}

/* setbits(x, p, n, y): returns x with the n bits that begin at
   position p set to the right most n bits of y, leaving the other bits 
   unchanged. 
*/
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    /* get the right most n bits of y and shift them */
    y = (y & ~(~0 << n)) << (p + 1 - n); 

    /* calculate the mask to set the n bits that begin at position p
       to zero
    */ 
    unsigned m = ~0 << (p + 1); /* 1 with p + 1 zeros at the right end */
    unsigned k = ~(~0 << (p + 1 - n)); /* zeros with p + 1 - n 1's at the
					  right end
				       */
    m = m | k; /* 1's with n zeros start at position p */
    
    /* apply the mask to x */ 
    x = x & m; 

    /* set the bits masked to y */ 
    x = x | y; 

    return x; 
}

