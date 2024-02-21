#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */

int get_line(char line[], int maxline);
void reverse(char s[]);

/* reverse input lines */
main()
{
	int len;
	char line[MAXLINE];     /* current input line */

	while ((len = get_line(line, MAXLINE)) > 0) {
		reverse(line);
		printf("%s", line);
	}

	return 0;
}


/* get_line:  read a line into a, return length */
int get_line(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}


/* reverse: reverse the characters in a string */
void reverse(char s[])
{
	int temp, i, len;

	for (len = 0; (s[len] != '\0' && s[len] != '\n'); ++len)
		;

	for (i = 0; i < len / 2; ++i) {
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
}
