#include <stdio.h>

/* count characters in input; 2nd version */

/*If you're typing at the terminal and you want to provoke
an end-of-file, use CTRL-D (unix-style systems) or CTRL-Z (Windows).*/

int main()
{
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}