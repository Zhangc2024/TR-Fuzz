#include <stdio.h>

/* count characters in input; 1st version */

/*If you're typing at the terminal and you want to provoke
an end-of-file, use CTRL-D (unix-style systems) or CTRL-Z (Windows).*/

int main()
{
    long nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
}