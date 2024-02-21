/*
 * Reverse the characters in each line.
 */

#include <stdio.h>

#define MAXLINE 10000		/* Max input line length. */

static int getaline(char *, int);
static void reverse(char *, int);

/* Reverse the characters in each line. */
int
main(void)
{
	int	len;		/* Current line length. */
	char	line[MAXLINE];	/* Current input line. */

	while ((len = getaline(line, MAXLINE)) > 0) {
		reverse(line, len);
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

/* reverse:  Reverse the character string order. */
static void
reverse(char *s, int len)
{
	int i, j, newline;
	char temp[MAXLINE];

	newline = 0;
	--len;			/* Skip \0. */
	if (s[len] == '\n') {
		newline = 1;
		--len;		/* Skip \n as well. */
	}
	j = 0;
	for (i = len; i >= 0; i--) {
		temp[j] = s[i];
		j++;
	}
	for (i = 0; i <= len; i++)
		s[i] = temp[i];
	if (newline)
		s[++len] = '\n';
	s[++len] = '\0';
}
