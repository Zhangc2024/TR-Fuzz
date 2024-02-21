#include <stdio.h>

#define IN          1 /* inside a word */
#define OUT         0 /* outside a word*/
#define MAXWORDLEN  11
#define MAXHIST     15

int main()
{
    int c, state, nc, i, maxfreq, len;
    int words[MAXWORDLEN];

    state = OUT;

    for (i = 0; i < MAXWORDLEN; ++i)
        words[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c =='\n' || c =='\t'){
            if (state == IN){
                if (nc <= 10)
                    ++words[nc-1];
                else
                    ++words[MAXWORDLEN - 1];
            }
            state = OUT;
        }
        else if (state == OUT){
            state = IN;
            nc = 1;
        }
        else if (state == IN)
            ++nc;
    }

    maxfreq = 0;
    for (i = 0; i < MAXWORDLEN - 1; ++i){
        if (words[i] > maxfreq)
            maxfreq = words[i];
    }
    for (i = 0; i < MAXWORDLEN; ++i){
        printf("%5d - %5d:  ", i+1, words[i]);
        if (words[i] > 0) {
            if ((len = words[i] * MAXHIST / maxfreq) < 1)
                len = 1;
        }
        else
            len = 0;
        while (len > 0) {
            putchar ('*');
            --len;
        }
        putchar('\n');
    }
    printf("There are %d words with length of at least %d\n", words[MAXWORDLEN-1], MAXWORDLEN);
}