#include <stdio.h>
#include <ctype.h>

#define MAXWORD 100
#define MINLEN 3

int getword(char *s, int max);

/* getword: read words from std input */
int main(int argc, char const *argv[])
{
	char word[MAXWORD];
	int len;

	while((len = getword(word, MAXWORD)) > 0) {
		if (len >= MINLEN && (isalpha(word[0]) || word[0] == '_')) {
			printf("%s ", word);
		}
	}
	return 0;
}

int getword(char *s, int max) {
	int c;
	char *p = s;
	while ((c = getchar()) && isspace(c))
		;

	if (c == EOF) {
		return 0;
	}

	*p++ = c;
	while (max-- > 0 && (c = getchar()) != EOF && (isalpha(c) || isdigit(c) || c == '_')) {
		*p++ = c;
	}
	*p = '\0';

	return (p - s);
}