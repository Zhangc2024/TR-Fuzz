/* Exercise 2-8 */

/* A function rightrot(x, n) that returns the value of the 
   integer x rotated to the right by n bit positions. 
*/ 

#include <stdio.h> 
#include <limits.h>

int rightrot(int x, int n); 

int main()
{
    printf("%d\n", rightrot(-1, 1));  // -1
    printf("%d\n", rightrot(-1, 32)); // -1
    printf("%d\n", rightrot(INT_MIN, 1)); // 1
    printf("%d\n", rightrot(INT_MIN + 1, 1)); // 1
    printf("%d\n", rightrot(INT_MAX - 1, 1)); // -4
}

/* rightrot(x, n): returns the value of the integer x rotated
   to the right by n bit positions. 

   The question only says that x is an integer, hence it is assumed
   to be a signed integer. The sign bit is rotated. 
*/ 
int rightrot(int x, int n)
{
    unsigned s = sizeof(unsigned) * CHAR_BIT; 
    unsigned u = (unsigned)x; 

    unsigned x1 = u >> (s - n); 
    unsigned x2 = u << n; 
    
    return x1 | x2; 
}
