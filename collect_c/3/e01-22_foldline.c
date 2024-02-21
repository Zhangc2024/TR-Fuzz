/*
 * Fold long lines.
 */

#include <stdio.h>

#define MAXCOL	80	/* Max column width in characters. */

static int	getaline(char *, int);
static size_t	strrcspnl(const char *, const char *, size_t);

/*
 * Fold long lines at MAXCOL. Split on whitespace to preserve words.
 * Lines without whitespace are split at MAXCOL. Doesn't handle tabs.
 */
int
main(void)
{
	int len, span;
	char line[BUFSIZ];	/* Current input line. */
	const char *tokens = " ";

	while ((len = getaline(line, BUFSIZ)) != -1) {
	 	span = strrcspnl(line, tokens, MAXCOL);
		printf("%d\n", span);
		printf("%s", line);
	}

	return (0);
}

/*
 * getaline:  read a line into `s'; return length, or -1 if EOF.
 */
static int
getaline(char *s, int lim)
{
	int c, i;

	c = 0;

	for (i = 0; ((c = getchar()) != EOF) && (i < (lim - 1)) &&
	    (c != '\n'); i++)
		s[i] = (char)c;
	if (c == EOF)
		return (-1);	/* POSIX */
	if (c == '\n')
		s[i++] = (char)c;
	s[i++] = '\0';

	return (i);
}

/*
 * The strrcspnl() function spans the NUL-terminated string s for the last
 * occurrence of any character in the NUL-terminated string tok up to len
 * characters and returns an index into the number of characters spanned.
 * If no characters in tok occur anywhere in s within len characters,
 * strrcspnl() returns an index into the shorter of len or the terminating NUL.
 */
static size_t
strrcspnl(const char *s, const char *tok, size_t len)
{
	int found = 0;
	size_t i;
	size_t ret = 0;
	const char *ps;
	const char *ptok;

	if (len == 0)
		return (0);
	for (i = 0, ps = s; (i < len) && (*ps != '\0'); i++, ps++) {
		for (ptok = tok; *ptok != '\0'; ptok++) {
			if (*ptok == *ps) {
				ret = ps - s + 1;
				found = 1;
				break;
			}
		}
	}
	if (found)
		return (ret);
	else
		return (len > i ? i - 1 : i);
}
