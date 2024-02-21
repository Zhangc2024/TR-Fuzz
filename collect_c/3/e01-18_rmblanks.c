/*
 * Remove blank lines, and trailing blanks and tabs from each input line.
 */

#include <stdio.h>

#define MAXLINE 10000		/* Max input line length. */

static int getaline(char *, int);
static void cleanaline(char *, int);

/* Remove blank lines, and trailing blanks and tabs from each input line. */
int
main(void)
{
	int	len;		/* Current line length. */
	char	line[MAXLINE];	/* Current input line. */

	while ((len = getaline(line, MAXLINE)) > 0) {
		cleanaline(line, len);
		/* Skip blank lines. */
		if (line[0] == '\n')
			continue;
		printf("%s", line);
	}

	return 0;
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

/* cleanaline:  Remove trailing blanks and tabs from input line. */
static void
cleanaline(char *s, int len)
{
	int i, nl;

	nl = 0;
	i = len - 1;		/* Skip \0. */

	if (s[i] == '\n') {
		nl = 1;
		--i;		/* Skip \0 and \n. */
	}
	while (s[i] == ' ' || s[i] == '\t')
		--i;
	++i;
	if (nl)
		s[i++] = '\n';
	s[i] = '\0';
}
