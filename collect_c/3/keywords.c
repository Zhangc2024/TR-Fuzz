#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct key {
	char *word;
	int count;
};

struct key keytab[] = {
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,

	"double", 0,

	"else", 0,

	"float", 0,

	"if", 0,

	"int", 0,

	"long", 0,

	"return", 0,

	"struct", 0,

	"switch", 0,

	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0
};

#define NKEYS (sizeof keytab / sizeof keytab[0]) // keytab length

int getword(char *, int);
struct key *binsearch(char *, struct key[], int);

int main(int argc, char const *argv[])
{
	struct key *k;
	char word[MAXWORD];

	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0])) {
			if ((k = binsearch(word, keytab, NKEYS)) != NULL) {
				k->count++;
			}
		}
	}

	for (k = keytab; k < keytab + NKEYS; k++) {
		if (k->count > 0) {
			printf("%4d %s\n", k->count, k->word);
		}
	}

	return 0;
}

int getword(char *s, int max) {
	int c;
	char *p;
	while ((c = getchar()) != EOF && isspace(c))
		;

	for (p = s; c != EOF && !isspace(c) && c != '\n' && (p - s) < max - 1; c = getchar()) {
		*p++ = c;
	}
	*p = '\0';

	return c;
}

struct key *binsearch(char *word, struct key tab[], int n) {
	struct key *l = tab;
	struct key *r = tab + (n - 1);
	struct key *mid;

	while (l < r) {
		mid = l + (r - l) / 2;
		if (strcmp(word, mid->word) > 0) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}

	if (strcmp(word, l->word) != 0) {
		return NULL;
	}

	return l;
}

