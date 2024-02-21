#include <stdio.h>

/* kopiowanie wejścia na wyjście */
main() 
{
    int c;
    int d, e;
    while ((c = getchar()) != EOF) 
    {
        d = (getchar() != EOF);
        printf("Wartosc getchar() != EOF to %d\n", d);
        putchar(c);
    }
}