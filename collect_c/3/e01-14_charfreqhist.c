/*
 * Character Frequency Histogram
 */

#include <stdio.h>

int
main(void)
{
	int ch, i, j; 
	int charfreq[128];	/* A count of each ASCII character. */

	for (i = 0; i <= 127; ++i)
		charfreq[i] = 0;

	while ((ch = getchar()) != EOF)
		++charfreq[ch];

	/* Only print the visible ASCII characters. */
	for (j = 32; j <= 127; ++j) {
		printf("%c %3d ", j, j); 
		for (i = 0; i < charfreq[j]; ++i)
			putchar('*');
		putchar('\n');
	}

	return 0;
}
