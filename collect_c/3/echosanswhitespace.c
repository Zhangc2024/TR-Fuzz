#include <stdio.h>

/* program to copy input to output; replaces single blanks with double */
main()
{
    int c, blank = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            blank = 0;
            putchar(c);
        }
        else if (blank == 0) {
            putchar(c);
            blank = 1;
        }
    }
}
