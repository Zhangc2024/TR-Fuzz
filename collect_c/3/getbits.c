#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main(void) {
    return 0;
}

/* get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n) & ~(~0 << n));
}
