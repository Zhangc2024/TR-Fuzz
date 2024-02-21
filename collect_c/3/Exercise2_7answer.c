# include <stdio.h>
unsigned invert(unsigned x, int p, int n);
main(){
    unsigned x = 214;                       /* binary: 11010110, decimal: 214 */
    printf("%u\n", invert(x, 5, 4));        /* binary: 11101010, decimal: 234 */
}
unsigned invert(unsigned x, int p, int n){
    return x ^ ((~(~0 << n) << (p+1-n)));
}
