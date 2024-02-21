/*
 * Word Length Histogram Vertical
 */

#include <stdio.h>

#define	IN		1	/* Inside a word */
#define	OUT		0	/* Outside a word */
#define MAXTERMWIDTH	75	/* Maximum terminal width */

int
main(void)
{
	int ch, prevstate, state; 
	int i, j, wordlen, maxwordlen, maxwordfreq;
	int wordfreq[MAXTERMWIDTH + 1];

	wordlen = maxwordlen = maxwordfreq = 0;
	for (i = 0; i < (MAXTERMWIDTH + 1); ++i)
		wordfreq[i] = 0;

	prevstate = state = OUT;
	while ((ch = getchar()) != EOF) {
		if (ch == ' ' || ch == '\t' || ch == '\n') {
			prevstate = state;
			state = OUT;
		} else {
			prevstate = state;
			state = IN;

			++wordlen;
		}
		if (prevstate == IN && state == OUT) {
			/* if end of word */
			prevstate = state;
			state = OUT;

			++wordfreq[wordlen];
			if (wordfreq[wordlen] > maxwordfreq)
				maxwordfreq = wordfreq[wordlen];
			if (wordlen > maxwordlen)
				maxwordlen = wordlen;
			wordlen = 0;
		}
	}

	if (maxwordlen > MAXTERMWIDTH)
		maxwordlen = MAXTERMWIDTH;

	for (j = 1; j <= maxwordfreq; ++j) {
		for (i = 1; i <= maxwordlen; ++i) {
			if (wordfreq[i] >= j)
				putchar('|');
			else
				putchar(' ');
		}
		putchar('\n');
	}

	return 0;
}
