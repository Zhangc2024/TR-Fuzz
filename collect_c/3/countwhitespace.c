#include <stdio.h>

/* program to count blanks, tabs, and newlines */
main()
{
    int c, ws;

    ws = 0;
    while((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n')
            ++ws;
    printf("%d\n", ws);
}
