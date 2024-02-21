/* Exercise 2-9 */

/* fast bit count */ 

#include <stdio.h> 
#include <limits.h> 

int bitcount(unsigned x); 

int main()
{
    printf("%d\n", bitcount(5)); // 2
    printf("%d\n", bitcount(INT_MAX)); // 31
    printf("%d\n", bitcount(UINT_MAX)); // 32
}

/* bitcount(x): count 1 bits in x */ 
int bitcount(unsigned x)
{
    int b; 

    for (b = 0; x != 0; x &= x - 1)
	++b; 

    return b; 
}
