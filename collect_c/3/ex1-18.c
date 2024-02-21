#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */

int get_line(char line[], int maxline);

/* truncate lines, and skip empty lines. */
main()
{
	int len;            /* current line length */
	char line[MAXLINE];     /* current input line */

	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len > 1) {
			printf("%s", line);
			if (line[len-1] != '\n') {
				printf("\n");
			}
		}
	}

	return 0;
}


/* get_line:  read a line into a, strip trailing whitespace, return length */
int get_line(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;

	for (; i > 0 && (s[i-1] == ' ' || s[i-1] == '\t'); --i)
		;

	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
