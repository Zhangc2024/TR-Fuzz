#include <stdio.h>

#define MAX_LENGTH 20

/* program to print a histogram of the lengths of input words */
main()
{
    int c, i, j, length, longest;
    int hist[20];

    length = 0;
    for (i = 0; i < MAX_LENGTH; ++i)
        hist[i] = 0;

    while ((c = getchar()) != EOF)
        if (c != ' ' && c!= '\n' && c != '\t')
            ++length;
        else if (length > 0 && length < 20) {
            ++hist[length];
            length = 0;
        }

    printf("Histogram of Word Lengths:\n\n");
    longest = hist[0];
    for (i = 0; i < MAX_LENGTH; ++i)
        if (hist[i] > longest)
            longest = hist[i];
    for (i = longest; i >= 0; --i) {
        for (j = 0; j < MAX_LENGTH; ++j) {
            if (hist[j] != 0) {
                if (i == 0)
                    printf("%d\t", j);
                else if (hist[j] < i)
                    printf(" \t");
                else
                    printf("*\t");
            }
        }
        printf("\n");
    }
            
}
