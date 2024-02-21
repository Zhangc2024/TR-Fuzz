#include <stdio.h>

#define MAXHIST    15           /* max length of histogram */
#define MAXWORD    11           /* max length of a word */
#define IN         1            /* inside a word */
#define OUT        0            /* outside a word */

/* print vertical histogram */
int main(){

    int c, i, j, nc, state;
    int maxvalue;               /* maximum value for wl[] */
    int overflow;               /* number of overflow words */
    int wl[MAXWORD];            /* word length counters */

    state = OUT;
    nc = 0;                     /* number of chars in a word*/
    overflow = 0;               /* number of words >= MAXWORD*/
    for(i = 0; i < MAXWORD; ++i)
        wl[i] = 0;
    while ((c = getchar()) != EOF){
        if(c ==' '||c == '\n'||c == '\t'){
            state = OUT;
            if(nc > 0){
                if(nc < MAXWORD)
                    ++wl[nc];
                else
                    ++overflow;
            }
            nc = 0;
        }
        else if (state == OUT){
            state = IN;
            nc = 1;             /* beginning of a new word*/
        }
        else
            ++nc;               /* inside a word */
    }
    maxvalue = 0;
    for(i = 1; i < MAXWORD; ++i){
        if(wl[i] > maxvalue)
            maxvalue = wl[i];
    }
    for(i = MAXHIST; i > 0; --i){
        for(j = 1; j < MAXWORD; ++j){
            if(wl[j]*MAXHIST / maxvalue >= i) {  /* wl[j]/maxvalue >= i/MAXHIST, with i decreasing.*/
                printf(" * ");                  /*Make sure only to print when i decreased to corresponding scale. */
            } else {
                printf("   ");
            }
        }
        putchar('\n');
    }
    for(i = 1; i < MAXWORD; ++i) {
        printf("%2d ", i);
    }
    putchar('\n');
    for(i = 1; i < MAXWORD; ++i) {
        printf("%2d ", wl[i]);
    }
    putchar('\n');
    if(overflow > 0) {
        printf("There are %d words >= %d\n", overflow, MAXWORD);
    }
}
