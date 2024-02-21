#include <stdio.h>

#define MAXWORDLEN 20    /* Maximom length of a word */
#define MAXNO 20	 /* Maximum no of words      */

#define IN 1             /* State of in a word       */
#define OUT 0            /* State of out a word      */


/* print a horizontal histogram of the lengths of words in  its input. */


int main() 
{

	int c, nc, i, j, nw;
	int wc;          /* Word Count */
	int word[MAXNO];
	int state;
	int maxwordlen;


	nc = nw = 0; 
	state = OUT; /* Assume we are not in a word starting out */

	/* Initialize words array */
	for (i = 0; i <= MAXWORDLEN; ++i) {
		word[i] = '0';
	}

	while ((c=getchar()) != EOF) {
		++nc;
		if ( c == '\n' || c == '\t' || c == ' ') {

			state = OUT;
			word[nw] = nc - 1;
			++nw;
			nc = 0; 
		}
	}

	for (i = MAXWORDLEN; i >= 1; --i) {
		for (j = 0; j <= nw; ++j) {
			if ( i <= word[j]) {
				printf(" * ");
			} else {
				printf("   ");
			}
		}
		putchar('\n');
	}
	printf("

	return 0;
}
