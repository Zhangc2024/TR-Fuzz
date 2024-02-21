#include <stdio.h>
#include <ctype.h>

#define MAXGETCHBUF 10

int getint(int *);

int main(int argc, char const *argv[])
{
	int c, i;
	while((c = getint(&i)) != EOF) {
		if (c != 0) {
			printf("%d ", i);	
		}
	}
	putchar('\n');

	return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn) {
	int i, c, sign, val;

	char getch(void);
	void ungetch(char);

	// skip spaces
	for (c = getch(); c != EOF && isspace(c); c = getch())
		;

	sign = 1;
	if (c == '-') {
		sign = -sign;
	}
	if (c == '-' || c == '+') {
		c = getch();		
	}

	for (val = 0; isdigit(c); c = getch()) {
		val = val * 10 + (c - '0');
	}

	if (c != EOF && val == 0) {
		while (!isspace(c)) {
			c = getch();
		}

		// not a number
		return 0;
	}

	*pn = val * sign;

	if (c != EOF) {
		ungetch(c);
	}

	return c;
}


char buf[MAXGETCHBUF];
int bufp = 0;

char getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(char c) {
	if (bufp >= MAXGETCHBUF) {
		printf("error: buffer is full");
		return;
	}

	buf[bufp++] = c;
}
