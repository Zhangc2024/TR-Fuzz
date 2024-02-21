# include <stdio.h>
# include <string.h>

# define IN  1
# define OUT 0
# define WORD_LIMIT 20

/* count lines, words, characters in input */
/* oh noes! there's a buffer overlflow attack here! can you find it? */

int main()
{
    
    int c, i, j, state;
    int wordlens[WORD_LIMIT];

    /* initialize  vars */
    for (i = 0; i < WORD_LIMIT; ++i)
        wordlens[i] = 0;
    state = OUT;    
    i = 0;
    
    /* count word lengths */
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++i;
        }
        ++wordlens[i];
    }

    /* print results*/
    printf("Lengths of first %d words:\n", WORD_LIMIT);
    for (i = 0; i < WORD_LIMIT; ++i) {
        printf("[%d]: ", i);
        for (j = 0; j < wordlens[i]; ++j)
            printf("+");
        printf("\n");
    }
    printf("\n");
}

void flag()
{
    printf("you found the ⚑!");
}
