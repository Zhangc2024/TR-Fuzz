/*
 * Print all input lines that are longer than 80 characters.
 */

#include <stdio.h>

#define MAXLINE 10000		/* Max input line size. */
#define MINLEN	(80 + 1)	/* Min line size to be printed. */

static int getaline(char *, int);

/* Print all input lines that are longer than MINLEN characters. */
int
main(void)
{
	int	len;			/* Current line length. */
	char	line[MAXLINE];		/* Current input line. */

	while ((len = getaline(line, MAXLINE)) > 0) {
		/* Don't consider NULL to be one of the characters. */
		if (len > MINLEN)
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
