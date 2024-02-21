#include <stdio.h>

#define NUM_CHARS 126

/* program to print a histogram of input character frequencies */
main()
{
    int c, i, j;
    int freq[NUM_CHARS];

    for (i = 0; i < NUM_CHARS; ++i)
        freq[i] = 0;

    while ((c = getchar()) != EOF)
        ++freq[c];
    
    printf("Histogram of character frequencies: ");
    for (i = 0; i < NUM_CHARS; ++i) {
        if (freq[i] != 0) {
            putchar(i);
            putchar(' ');
            for (j = 0; j < freq[i]; ++j)
                putchar('*');
            putchar('\n');
        }
    }
}

