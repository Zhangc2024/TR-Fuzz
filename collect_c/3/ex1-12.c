#include <stdio.h>

#define IN  1   /* inside a word */
#define OUT 0   /* outside a word */

main()
{
	int c, state;

	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN)
				putchar('\n');
			state = OUT;
		}
		else {
			putchar(c);
			state = IN;
		}
	}
}
