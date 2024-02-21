#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch();
void ungetch(int);
int getint(int *pn);
int getfloat(float *pn);

int getch() {
	extern int bufp;
	int c;

	c = (bufp > 0) ? buf[--bufp] : getchar();

	return c;
}

void ungetch(int c) {
	extern int bufp;
	if (bufp >= BUFSIZE)
		puts("Buffer is full.");

	buf[bufp++] = c;
}

int getint(int *pn) {
	int c, d, sign;
	while (isspace(c = getch()))
		;

	if (c != EOF && !isdigit(c) && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		d = c;
		if ((c = getch()) != EOF && !isdigit(c)) {
			ungetch(c);
			ungetch(d);

			return d;
		}
	}

	*pn = 0;
	while (isdigit(c)) {
		*pn = 10 * (*pn) + c - '0';
		c = getch();
	}
	*pn *= sign * (*pn);

	if (c != EOF)
		ungetch(c);
	return c;

}

int getfloat(float *pn) {
	int c, sign, nexp;
	float pow;
	while (isspace(c = getch()))
		;
	if (c != EOF && !isdigit(c) && c != '+' && c != '-' && c != 'e'
			&& c != 'E') {
		ungetch(c);
		return 0;
	}

	//sign part
	sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+')
		c = getch();

	//number part before dot.
	for (*pn = 0.; isdigit(c); c = getch())
		*pn = 10. * *pn + c - '0';

	//number part after dot. before e(E)
	if (c == '.')
		c = getch();
	for (pow = 1.; isdigit(c); c = getch()) {
		pow *= 10.;
		*pn = 10. * *pn + c - '0';
	}
	*pn *= sign / pow;

	//significant part
	if (c == 'e' || c == 'E') {
		sign = ((c = getch()) == '-') ? -1 : 1;
		if (c == '-' || c == '+')
			c = getch();
	}
	for (nexp = 0; isdigit(c); c = getch())
		nexp = 10 * nexp + c - '0';
	if (sign == 1)
		while (nexp-- > 0)
			*pn *= 10.;
	else
		while (nexp-- > 0)
			*pn /= 10.;

	//completion of a floating number
	if (c != EOF)
		ungetch(c);
	return c;
}
int main() {
	float arr[10];

	for (int i = 0; i < 4; i++) {
		getfloat(&arr[i]);
		printf("%f\n", arr[i]);
	}
	return EXIT_SUCCESS;
}
