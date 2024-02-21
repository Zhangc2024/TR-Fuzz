#include <stdio.h>

#define IN 1
#define OUT 0
#define WORDLEN 20


/* print a horizontal histogram of the lengths of words in  its input. */


int main() 
{

	int c, nc, i, wc;
	int words[WORDLEN];
	int state;


	nc = 0; /* Number of characters in word */
	wc = 0; /* Keep track of the number of words we process */
	state = OUT; /* Assume we are not in a word starting out */


	/* Initialize words array */
	for (i = 0; i <= WORDLEN; ++i) {
		words[i] = '0';
	}

	while ((c=getchar()) != EOF) {
		if ( c == '\n' || c == '\t' || c == ' ') {
			state = OUT;
		} else if (state == OUT) {
			/* Beginning of new word */
			state = IN;
			nc = 1;
			++wc;
		} else {
			/* We are in the word now  count the number 
			 * of characters in the word */
			++nc;
		}

		if (state == OUT) {
			printf("Word %2d is %2d characters: ", wc, nc);
			for (i = 1; i <= nc; ++i) {
				putchar('*');
			}
			printf("\n");
		}
	}
}
