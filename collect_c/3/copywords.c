# include <stdio.h>

# define IN  1
# define OUT 0

/* read intput and print it back 1 word per line */

int main()
{
    int c, state;
    state = IN;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            putchar('\n');
        }
        putchar(c);
    }
}
