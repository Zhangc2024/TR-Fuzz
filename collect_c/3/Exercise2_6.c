# include <stdio.h>
// Right adjusted eg: postion 4(p), 3(n) digits, like (4, 3, 2), 1, 0; the nums
// in parentheses are what we want to reserve.
unsigned setbits(unsigned x, int p, int n, unsigned y);
int main() {
    unsigned x = 27;                            /* binary: 11011 */
    unsigned y = 21;                            /* binary: 10101 */
    printf("%u\n", setbits(x, 3, 2, y));        /* binary: 10111, decimal: 23 */
    return 0;
}
unsigned setbits(unsigned x, int p, int n, unsigned y){
    // 1. set x's corresponding parts to 0s
    // 2. keep y's corresponding part, and set the rest to 0s
    // Then x | y
    return (x & ~(~(~0 << n) << (p+1-n))) |
            (y & (~(~0 << n) << (p+1-n)));
}
