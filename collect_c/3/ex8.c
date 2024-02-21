#include <stdio.h>

/* Ex 1-9. Program to copy input to output. Replacing each string of one or more blanks by a single blank.  */

int main()
{
    
    int c;
    int blank_seen = 0;

    while((c = getchar()) != EOF) 
    {
        if (c == ' ' || c == '\t') {
            
            if (!blank_seen)
                putchar(' ');

            blank_seen = 1;

        } else {
            
            putchar(c);
            blank_seen = 0;

        }
    }

    return 0;
}
