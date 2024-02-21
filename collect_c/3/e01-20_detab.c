/*
 * detab: Replace tabs with blanks.
 */

#include <stdio.h>

#define TABSIZE	8

/* detab:  Replace tabs with blanks. */
int
main(void)
{
	int ch, i;

	for (i = 0; (ch = getchar()) != EOF; i++) {
		if (ch == '\n')
			i = 0;
		if (ch == '\t') {
			putchar(' ');
			for (; i % TABSIZE; i++)
				putchar(' ');
		} else
			putchar(ch);
	}

	return (0);
}
