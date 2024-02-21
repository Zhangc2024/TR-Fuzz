#include <stdio.h>

/* count lines in input */

int main()
{
    int c, nb, nt, nl;
    nl = 0;
    nt = 0;
    nb = 0;

    while ((c = getchar()) != EOF){
        if (c == '\n')
            ++nl;
        if (c == '\t')
            ++nt;
        if (c == ' ')
            ++nb;
    }
    printf("new lines: %d, new  tabs: %d, new blanks: %d\n", nl, nt, nb);
}
