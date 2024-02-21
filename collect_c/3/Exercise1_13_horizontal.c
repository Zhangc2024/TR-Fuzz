# include<stdio.h>

/* Set the maximum number of words and storage of histogram*/

#define MAXHIST 15
#define MAXWORD 11
#define IN      1
#define OUT     0

/* print horizontal histogram */
int main(){

    int c, i, nc, state;
    int len;                           /* length of each bar */
    int maxvalue;                      /* maximum value for wl[] */
    int overflow;                      /* number of overflow words */
    int wl[MAXWORD];                   /* word length counters */

    state = OUT;
    nc = 0;                            /* number of chars in a word */
    overflow = 0;                      /* number of words >= MAXWORD */
    for(i = 0; i < MAXWORD; ++i){
        wl[i] = 0;
    }
    while((c = getchar()) != EOF) {
        if(c == ' '||c == '\n'||c=='\t'){
            state = OUT;
            if(nc > 0){                /* to make sure whether it's just outside, or there was consecutive blank */
                if(nc < MAXWORD)
                    ++wl[nc];
                else
                    ++overflow;
            }
            nc = 0;                    /* after the initial blank, make the rest blank wouldn't be counted as words */
        }
        else if (state == OUT) {        /* encountering the first character of a word */
            state = IN;
            nc = 1;
        }
        else                           /* already inside a word */
            ++nc;
    }
    maxvalue = 0;
    for(i = 1; i < MAXWORD; ++i){
        if(wl[i] > maxvalue)
            maxvalue = wl[i];
    }
    for(i = 1; i < MAXWORD; ++i){
        printf("%5d - %5d :",i, wl[i]);
        if(wl[i] > 0){
            if((len = wl[i] * MAXHIST / maxvalue) <= 0) {  /* wl[i]/maxvalue should be between 0 and 1, excluding 0 while including 1 */
                len = 1;                                /* the variable len scales the value in wl[i] according to MAXHIST and maxvalue */
            }
        } else {
            len = 0;
        }
        while (len > 0){
            putchar('*');
            --len;
        }
        putchar('\n');
    }
    if(overflow > 0)
        printf("There are %d words >= %d\n", overflow, MAXWORD);
}
