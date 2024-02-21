#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#define TABINC	8

/*	Ex 1-20 1-21	*/

void detab() {
	int c, nb, pos = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			nb = TABINC - (pos % TABINC);
			while (nb-- > 0)
				putchar(' ');

			pos = 0;
		} else if (c == '\n') {
			pos = 0;
			putchar(c);
		} else {
			putchar(c);
			pos++;
		}

	}
}

void entab() {
	int c, nb, nt, pos;
	pos = nb = nt = 0;

	while ((c = getchar()) != EOF) {
		pos++;
		for (; c == ' '; pos++) {
			if (pos % TABINC != 0)
				nb++;
			else
				nt++, nb = 0;
			c = getchar();
		}

		/*	Print Tabs	*/
		for (; nt > 0; nt--)
			putchar('\t');

		/*	Check if c is a tab	*/
		if (c == '\t') {
			nb = 0;
			pos = pos + TABINC - (pos % TABINC);
		}
		if (c == '\n')
			pos = 0;

		for (; nb > 0; nb--)
			putchar(' ');

		if (c != EOF) {
			putchar(c);
		}
	}
}

int main() {
	entab();
}
