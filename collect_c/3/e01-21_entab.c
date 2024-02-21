/*
 * Replace blanks with tabs and blanks as to keep the same spacing.
 */

#include <stdio.h>

#define TABSIZ 8

static int getaline(char *, int);
static void entab(char *, const char *);

/*
 * Replace blanks with tabs and blanks as to keep the same spacing.
 */
int
main(void)
{
	int len;
	char line[BUFSIZ];	/* Current input line. */
	char tabbed[BUFSIZ];	/* Cooked string with tabs. */

	while ((len = getaline(line, BUFSIZ)) != -1) {
		entab(tabbed, line);
		printf("%s", tabbed);
	}

	return (0);
}

/* getaline:  read a line into `s'; return length, or -1 if EOF. */
static int
getaline(char *s, int lim)
{
	int c, i;

	c = 0;

	for (i = 0; ((c = getchar()) != EOF) && (i < lim - 1) &&
	    (c != '\n'); i++)
		s[i] = (char)c;
	if (c == EOF)
		return (-1);	/* POSIX */
	if (c == '\n')
		s[i++] = (char)c;
	s[i++] = '\0';

	return (i);
}

/* entab:  replace blanks with tabs and blanks. */
static void
entab(char *dst, const char *src)
{
	int blanks, mark, n, tflag;
	const char *tok;

	const char delim = ' ';
	blanks = mark = n = tflag = 0;

	while (*src != '\0') {
		/* Copy characters that are not blanks. */
		while (*src != delim) {
			*dst++ = *src++;
			n++;
		}

		tok = src;	/* Save the location of the first blank. */
		mark = n;
		tflag = 0;

		while (*src++ == delim) {
			n++;
			blanks++;
			if ((n % TABSIZ == 0) && (blanks > 1)) {
				tflag = 1;
				break;
			}
		}
		blanks = 0;
		if (tflag == 1) {
			tflag = 0;
			*dst++ = '\t';
		} else {
			src = tok;	/* Not enough blanks for a tab. */
			while (mark++ != n)
				*dst++ = *src++;
		}
	}
}
