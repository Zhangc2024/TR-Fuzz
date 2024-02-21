#include <stdio.h>

#define CHARS_CNT 255

int main() {
    int i, j, c, totalCnt, minChar, maxChar;
    int counts[CHARS_CNT];
    int freqs[CHARS_CNT];

    minChar = CHARS_CNT;
    maxChar = 0;
    for (i = 0; i < CHARS_CNT; i++)
        counts[i] = freqs[i] = 0;

    while ((c = getchar()) != EOF) {
        counts[c]++;
        totalCnt++;

        if (c > maxChar) maxChar = c;
        if (c < minChar) minChar = c;
    }

    int maxFreq, minFreq;
    minFreq = 100;
    maxFreq = 0;
    for (i = minChar; i <= maxChar; i++) {
        freqs[i] = (int)(((float)counts[i] / (float)totalCnt) * 100);
        if (freqs[i] > maxFreq && counts[i] > 0) maxFreq = freqs[i];
        if (freqs[i] < minFreq && counts[i] > 0) minFreq = freqs[i];
    }

    for (i = maxFreq; i >= minFreq; i--) {
        printf("%2d |", i);
        for (j = minChar; j <= maxChar; j++) {
            if (counts[j] > 0) printf(freqs[j] >= i ? " *" : "  ");
        }
        printf("\n");
    }

    printf("----");
    for (j = minChar; j <= maxChar; j++) {
        if (counts[j] > 0) printf("--");
    }

    printf("\n   |");
    for (j = minChar; j <= maxChar; j++) {
        if (counts[j] > 0) {
            if (j == '\n') printf("\\n");
            else printf(" %c", j);
        }
    }

    printf("\n");
    return 0;
}