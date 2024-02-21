#include <stdio.h>

/* count lines in input */

int main()
{
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF)
        /*printf("Value of input: %d\n", c);*/
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}
