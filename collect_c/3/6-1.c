#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

typedef struct key {
	char *word;
	int count;
} key;
key keytab[] = { { "break", 0 }, { "case", 0 }, { "char", 0 }, { "for", 0 }, {
		"int", 0 }, { "static", 0 }, { "while", 0 } };

#define MAXLEN	1000
#define NKEYS	(sizeof keytab / sizeof (key))

/*	Ex 6-1	*/

int getch();
void ungetch(int c);

int getword(char *word, int lim) {
	void incmt(int);

	int c, d, type;
	char *w = word; /*	Current Pointer	*/

	/*	Consume Blanks	*/
	while (isspace(c = getch()))
		;

	/*	Match Patterns	*/
	type = c;

	if (isalpha(c) || c == '#' || c == '_') {
		/*	a word	*/
		for (*w++ = c; --lim > 1 && (isalnum(c = getch()) || c == '_');)
			*w++ = c;

		if (lim != 1)
			ungetch(c);

	} else if (c == '/') {
		if ((c = getch()) == '*' || c == '/')
			/*	A Comment	*/
			incmt(c);
	} else if (c == '\'' || c == '"') {
		/*	A String	*/
		d = c;
		while (--lim > 0 && (c = getch()) != d && c != EOF)
			if (c != '\\' || (c = getch()) != EOF)
				*w++ = c;
	}

	*w = '\0';
	return type;
}

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	int binsearch(char*, key*, int);
	int i, c, n;
	char word[MAXLEN];
	while ((c = getword(word, MAXLEN)) != EOF) {
		if (isalpha(c) && (n = binsearch(word, keytab, NKEYS)) != -1)
			keytab[n].count++;
	}

	for (i = 0; i < NKEYS; i++)
		if (keytab[i].count > 0)
			printf("%4d %s\n", keytab[i].count, keytab[i].word);

	return EXIT_SUCCESS;
}

int binsearch(char *word, key tab[], int n) {
	int lo, hi, mid;
	int cmp;
	lo = 0;
	hi = n - 1;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if ((cmp = strcmp(word, tab[mid].word)) < 0)
			hi = mid - 1;
		else if (cmp > 0)
			lo = mid + 1;
		else
			return mid;
	}

	return -1;
}
/*	Jump Over a Comment Block	*/
void incmt(int type) {
	assert(type == '*' || type == '/');

	int c, lastc;
	switch (type) {
	case '*':
		// Comment Format  /* ... */
		for (c = getch();
				(lastc = c) != EOF && ((c = getch()) != '/' || lastc != '*');)
			;

		break;
	case '/':
		/*	Comment Format // ... \n */
		while ((c = getch()) != '\n' && c != EOF)
			;
		break;
	default:
		break;
	}
}

static int lastc;
int getch() {
	int c;
	if (lastc != '\0') {
		c = lastc;
		lastc = '\0';
	} else
		c = getchar();
	return c;
}

void ungetch(int c) {
	assert(!lastc);

	lastc = c;
}
