# include <stdio.h>
unsigned invert(unsigned x, int p, int n);
int main() {
    /* binary: 11(0101)10, decimal: 214 */
    /* binary: 11(1010)10, decimal: 234 */
    unsigned x = 214;                       
    printf("x is %u, after inverting: %u\n",x, invert(x, 5, 4));
    return 0;
}
unsigned invert(unsigned x, int p, int n){
    // Similar to exercise 2.6, needs to modified x's or operation
    // set first x's corresponding parts to 0s, and keep rest unchanged;
    // set the other x's corresponding parts to invert, rest to 0s
    return (x&(~(~(~0 << n) << (p+1-n)))) |
            ((~x) & (~(~0 << n) << (p+1-n)));
}
