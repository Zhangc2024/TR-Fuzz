#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFLINES 10   /* default # of lines to print */
#define LINES    100  /* max # of lines to print */
#define MAXLEN   100  /* max length of an input line */

void error(char *);
int getline(char *, int);

/* print last n lines of the input */
main(int argc, char *argv[])
{
	char *p;
	char *buf;				/* pointer to larger buffer */
	char *bufend;			/* end of the buffer */
	char line[MAXLEN]; 		/* current input line */
	char *lineptr[LINES];	/* pointer to lines read */
	int first, i, last, len, n, nlines;
	
	if (argc == 1)
		n = DEFLINES;
	else if (argc == 2 && (*++argv)[0] == '-')
		n = atoi(argv[0]+1);
	else
		error("usage: tail [-n]");
	if (n < 1 || n > LINES)	/* unreasonable value for n */
		n = LINES;
	for (i = 0; i < LINES; i++)
		lineptr[i] = NULL;
	if ((p = buf = malloc(LINES * MAXLEN)) == NULL)
		error("tail: cannot allocate buf");
	bufend = buf + LINES * MAXLEN;
	last = 0;
	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0){
		if (p + len + 1 >= bufend)
			p = buf;		/* buffer wrap around */
		lineptr[last] = p;
		strcpy(lineptr[last], line);
		if (++last >= LINES)
			last = 0;		/* ptrs to buffer wrap around */
		p += len + 1;
		nlines++;
	}
	if (n > nlines)			/* req. lines more than rec? */
		n = nlines;
	first = last - n;
	if (first < 0)
		first += LINES;
	for (i = first; n-- > 0; i = (i + 1) % LINES)
		printf("%s", lineptr[i]);
	return 0;
}

void error(char *s)
{
	printf("%s\n", s);
	exit(1);
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
