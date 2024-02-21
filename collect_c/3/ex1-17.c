#include <stdio.h>
#define MINLINE 80    /* minimum input line length */

int get_line(char line[], int maxline);

/* print all input lines that are longer than 80 characters. */
main()
{
	int c, len;
	char line[MINLINE];     /* current input line */

	while ((len = get_line(line, MINLINE)) > 0) {
		if (len >= MINLINE) {
			printf("%s", line);
			if (line[len-1] != '\n') {
				while ((c = getchar()) != EOF && c != '\n')
					printf("%c", c);
				if (c == '\n')
					printf("%c", c);
			}
		}
	}

	return 0;
}


/* get_line:  read a line into a, return length */
int get_line(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	s[i] = '\0';
	return i;
}
