#include <stdio.h>

/* kopiowanie wejścia na wyjście */
main() 
{
    int c;
    while ((c = getchar()) != EOF) 
    {
        putchar(c);
    }
}