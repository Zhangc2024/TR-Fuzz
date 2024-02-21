#include <stdio.h>
#define NOBLANK 'a'

main()
{
    int c, lastc;
    lastc = NOBLANK;

    while ((c = getchar()) != EOF){
        if ( c != ' ')
            putchar(c);
        if ( c == ' ')
            if ( lastc != ' ')
                putchar(' ');
        lastc = c;
    }
}
