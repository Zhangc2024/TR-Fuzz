#include <stdio.h>

/* Exercise 1-12. Write a program that prints its input one word per line. */

#define SEEN    1
#define NOT_SEEN 0

int main()
{
    int c;
    int is_word_seen = NOT_SEEN;

    while((c = getchar()) != EOF)
    {
       if (c == ' ' || c == '\n' || c == '\t') {
           
           if (is_word_seen == NOT_SEEN)
                printf("\n");

           is_word_seen = SEEN; 

       } else {
            
           is_word_seen = NOT_SEEN;

           putchar(c);

       }        
    }

    return 0;
}
