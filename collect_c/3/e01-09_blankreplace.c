/*
 * Blank Replace
 */

#include <stdio.h>

int
main(void)
{
	int ch, prevch;

	ch = prevch = 0;
	while ((ch = getchar()) != EOF) {
		if (ch == ' ' && prevch == ' ')
			continue;
		prevch = ch;
		putchar(ch);
	}

	return 0;
}
