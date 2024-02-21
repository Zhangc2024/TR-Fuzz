#include <stdio.h>

#define MAXHIST 50           /* max length of histogram                */
#define MAXWORD 30           /* max length of a word                   */
#define IN      1            /* inside a word                          */
#define OUT     0            /* outside a word                         */

/* print a horizontal histogram of the lenght of wordss in it's sinput.*/

int main()
{

	int c, i, nc, state;
	int len;         /* lenght of value for wl[] */
	int maxvalue;    /* max value for wl[] */
	int overflow;    /* number of overflow wordss */
	int wl[MAXWORD]; /* word length counters */


	state = OUT;

	nc = 0;          /* number of char sin a word */
	overflow = 0;    /* number of words >= MAXWORD*/
	for (i = 0; i < MAXWORD; ++i)
		wl[i] = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c== '\n' || c == '\t') {
			state = OUT;
			if (nc > 0) {
				if (nc < MAXWORD)
					++wl[nc];
				else
					++overflow;
			}
			nc = 0;
		} else if (state == OUT) {
			state = IN;
			nc = 1; /* beginning of a new word   */
		} else
			++nc;
	}

	maxvalue = 0;
	for (i = 1; i < MAXWORD; ++i)
		if (wl[i] > maxvalue)
			maxvalue = wl[i];

	for (i = 1; i < maxvalue; ++i) {
		printf("%5d - %5d : ", i, wl[i]);
		if (wl[i] > 0) {
			if ((len = wl[i] = MAXHIST / maxvalue) <= 0)
				len = 1;
		} else
			len = 0; 
		while (len >0) {
			putchar('X');
			--len;
		}
		putchar('\n');
	}
	if (overflow > 0)
		printf("There are %d words >= %d\n", overflow, MAXWORD);
}
