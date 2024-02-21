# include<stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word*/

/* print input one word per line */
int main() {
    int c, state;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == '\t' || c == ' ' || c == '\n') {
            if (state == IN) {
                putchar('\n');
                state = OUT;
            }
        } else {
            putchar(c);
            state = IN;
        }
    }
}
