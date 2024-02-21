#include<stdio.h>

#define IN 1
#define OUT 0

/*
 * count lines, words, and characters
 */
int main(){
    int c, nl, nw, nc, state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF){
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT){
            state = IN;
            ++nw;
        }
    }
    printf("chars: %d words: %d lines: %d\n", nc, nw, nl);
    return 0;
}
