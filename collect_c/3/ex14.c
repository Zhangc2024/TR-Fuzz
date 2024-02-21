#include <stdio.h>
#include <math.h>

/* Exercise 1-14. Horizontal Histogram of frequencies of different characters in input */

int main()
{
    int n_digit[10], n_small_alphabet[26], n_big_alphabet[26];
    
    int i, l, c, nc, freq;
    
    char *atoz = "abcdefghijklmnopqrstuvwxyz";
    char *AtoZ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    nc = 0;

    for (i = 0; i < 26; i++)
    {
        if (i < 10)
            n_digit[i] = 0;

        n_small_alphabet[i] = 0;
        n_big_alphabet[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {       
        if (c != ' ' && c != '\t' && c != '\n') {

            nc++;
            
            if (c >= '0' && c <= '9')
                ++n_digit[c - '0'];

            if (c >= 'a' && c <= 'z')
                ++n_small_alphabet[c - 'a'];

            if (c >= 'A' && c <= 'Z')
                ++n_big_alphabet[c - 'A'];

        }
    }

    for (i = 0; i < 10; i++)
    {
        if (n_digit[i] != 0) {

            printf("%d : ", i);
            
            freq = 10.0 * (log10(nc) + 1) * (float) n_digit[i] / (float) nc;

            for (l = 0; l < freq; l++)
                printf("-");
                        
            printf("\n");
        }
    }

    for (i = 0; i < 26; i++)
    {
        if (n_small_alphabet[i] != 0) {
            
            printf("%c : ", atoz[i]);

            freq = 10.0 * (log10(nc) + 1) * (float) n_small_alphabet[i] / (float) nc;

            for (l = 0; l < freq; l++)
                printf("-");

            printf("\n");
        }
    }
    
    for (i = 0; i < 26; i++)
    {
         if (n_big_alphabet[i] != 0) {
            
            printf("%c : ", AtoZ[i]);

            freq = 10.0 * (log10(nc) + 1) * (float) n_big_alphabet[i] / (float) nc;

            for (l = 0; l < freq; l++)
                printf("-");

            printf("\n");
        }
    }

    return 0;
}
