# include<stdio.h>
// Rotate to the righ by n bit positions means take the rightmost n
// bits to the very left of the word.
unsigned rightrot(unsigned x, int n);
int wordlength(void);
int main() {
    // binary: 1111001
    unsigned x = 121;
    int n = 3;
    // on this machine it's 32
    printf("The unsigned word length on this machine is %d\n", wordlength());
    // it would be 00100000000000000000000000001111
    printf("rotate %u to the right by %d positions is: %u\n", x, n, rightrot(x, 3));
    return 0;
}
/* rightrot: rotate x to the right by n positions */
unsigned rightrot(unsigned x, int n){
    int wordlength(void);
    // rightmost bit
    int rbit;
    while(n-- > 0){
        rbit = (x & 1) << (wordlength() - 1);
        /* shift x 1 position right */
        x = x >> 1;
        x = x | rbit;
    }
    return x;
}
/* wordlength: computes word length of the machine */
int wordlength(void) {
    int i;
    unsigned v = (unsigned) ~0;
    // v is unsigned, so shift right will fill left side by 0
    for(i = 1; (v = v >> 1) > 0; i++)
        ;
    return i;
}
