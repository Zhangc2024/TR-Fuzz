/*
 * One Word Per Line
 */

#include <stdio.h>

#define	IN	1	/* Inside a word */
#define	OUT	0	/* Outside a word */

int
main(void)
{
	int c, prevstate, state; 

	prevstate = state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			prevstate = state;
			state = OUT;
		} else {
			prevstate = state;
			state = IN;
			putchar(c);
		}
		if (prevstate == IN && state == OUT) {
			prevstate = state;
			state = OUT;
			putchar('\n');
		}
	}
	
	return 0;
}
