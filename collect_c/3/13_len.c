#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLEN 20

int main() {
    int state, c, current, i;
    int hist[MAXLEN];

    for (i=0; i<MAXLEN; ++i)
        hist[i] = 0;

    current = 0;
    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                ++hist[current-1];
                current = 0;
                state = OUT;
            }
            continue;
        }

        state = IN;
        ++current;
    }

    int maxc;
    maxc = 0;
    for (i=0; i<MAXLEN; ++i)
        if (hist[i] > maxc)
            maxc = hist[i];

    int h;
    for (h=maxc; h>0; --h) {
        printf("%3d |", h);

        for (i=0; i<MAXLEN; ++i) {
            if (hist[i] >= h)
                printf("  *");
            else
                printf("   ");
        }

        putchar('\n');
    }

    printf("-----");
    for (i=0; i<MAXLEN; ++i)
        printf("---");

    printf("\n    |");
    for (i=0; i<MAXLEN; ++i)
        printf("%3d", i+1);

    printf("\n");
    return 0;
}