#include <stdio.h>

main() 
{
    int c, nl, sp, tab;

    nl = 0, sp = 0, tab = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
        else if (c == ' ')
            ++sp;
        else if (c == '\t')
            ++tab;
    printf("Nowych linii: %d. Tabulacji: %d. Spacji: %d.\n", nl, tab, sp);
}
