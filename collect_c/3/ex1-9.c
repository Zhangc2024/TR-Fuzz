#include <stdio.h>

#define IN  1   /* inside a sequence of blanks */
#define OUT 0   /* outside a sequence of blanks */

/* copy input to output, replacing one or more blanks by a single blank */
main()
{
	int c, state;
	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			state = IN;
		}
		else {
			if (state == IN) {
				putchar(' ');
			}
			putchar(c);
			state = OUT;
		}
	}
	if (state == IN) {
	 	putchar(' ');
	}
}
