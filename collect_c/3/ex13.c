#include <stdio.h>

/* Exercise 1-13: Horizontal Histogram of lengths of input */

#define WORD_SEEN 1
#define WORD_UNSEEN 0

int main()
{
    int c, i, nc, is_word_seen;

    nc = 0;
    is_word_seen = WORD_UNSEEN;

    while((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t') {
            
            if (is_word_seen == WORD_UNSEEN) {
                
                for (i = 0; i < nc; i++)
                    printf("-");
                
                printf("\n");
                nc = 0;
            }    
           
            is_word_seen = WORD_SEEN;

        } else {

            is_word_seen = WORD_UNSEEN;
            nc++;

        }
    }

    return 0;
}
