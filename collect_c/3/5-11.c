#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <errno.h>
#define DTABINC	4
#define MAXLEN 	100

bool istpos(int pos, bool tabs[]) {
	return (pos >= MAXLEN) ? false : tabs[pos];
}

void error(char*);
void settab(int argc, char *argv[], bool tabs[]) {
	int i;
	/*	Parse Arguments	*/
	if (argc == 1) {
		for (i = 1; i < MAXLEN; i++)
			if (!(i % DTABINC))
				tabs[i] = true;
	} else {
		while (--argc > 0) {
			if ((i = (int) strtol(*++argv, NULL, 0))
					< 0|| i >= MAXLEN || errno == ERANGE)
				error("Wrong.");

			tabs[i] = true;
		}

	}
}

void entab(bool tabs[]) {
	int c, pos;
	int nb, nt;
	nb = nt = 0;

	while ((c = getchar()) != EOF) {
		pos++;

		/*	Read Blanks	*/
		for (; c == ' '; pos++) {
			if (istpos(pos, tabs))
				nt++, nb = 0;
			else
				nb++;
			c = getchar();
		}

		/*	Print Tabs	*/
		for (; nt > 0; nt--)
			putchar('t');

		if (c == '\t') {
			nb = 0;
			while (!istpos(pos++, tabs))
				;
		}

		if (c == '\n')
			pos = 0;

		/*	Print Blanks	*/
		for (; nb > 0; nb--)
			putchar('b');

		if (c != EOF) {
			if (c == '\t')
				putchar('t');
			else
				putchar(c);
		}
	}
}

void detab(bool tabs[]) {
	int c, pos;

	pos = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			do
				putchar(' ');
			while (!tabs[++pos]);
			continue;
		}

		putchar(c);
		pos++;
		if (c == '\n')
			pos = 0;
	}
}

/*	Ex 5-11 */
int main(int argc, char *argv[]) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	bool tabs[MAXLEN] = { false };/*	Init tabs	*/
	settab(argc, argv, tabs);
	entab(tabs);
	detab(tabs);
}

void error(char *msg) {
	puts(msg);
	exit(1);
}
