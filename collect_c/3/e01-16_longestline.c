/*
 * Print the longest input line.
 */

#include <stdio.h>

#define MAXLINE 10000	/* Max input line size. */

static int getaline(char *, int);
static void copyaline(char *, char *);

/* Print longest input line. */
int
main(void)
{
	int	len;			/* Current line length. */
	int	max;			/* Maximum length seen so far. */
	char	line[MAXLINE];		/* Current input line. */
	char	longest[MAXLINE];	/* Longest line saved here. */

	max = 0;

	while ((len = getaline(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copyaline(longest, line);
		}
	}
	/* There was a line. */
	if (max > 0) {
		printf("The longest line has %d characters.\n", max);
		printf("%s", longest);
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

/* copyaline:  copy `from' into `to'; assume `to' is big enough. */
static void
copyaline(char *to, char *from)
{
	int i;

	for (i = 0; (to[i] = from[i]) != '\0'; ++i)
		;
}
