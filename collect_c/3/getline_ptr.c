#include <stdio.h>

#define MAXLINE 1000

int getline_ptr(char *, int);

int main(int argc, char const *argv[])
{
	char line[MAXLINE];

	while (getline_ptr(line, MAXLINE) > 0) {
		printf("%s", line);
	}

	return 0;
}

int getline_ptr(char *s, int limit) {
	int c;
	char *p = s;
	while ((c = getchar()) != EOF && c != '\n' && (p-s) < limit) {
		*p++ = c;
	}

	if (c == '\n') {
		*p++ = c;
	}
	*p = '\0';

	return (p - s);
}