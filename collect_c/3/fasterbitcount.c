#include <stdio.h>

int bitcount(unsigned x);

main()
{
    unsigned int x = 0x1f93ff;
    int c = bitcount(x);

    printf("bitcount(%u (%x)) =  %d\n", x, x, c);
    
    return 0;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int b = 0;

    while (x != 0)
        if (x &= (x-1))
            b++;
    b++;
    return b;
}
