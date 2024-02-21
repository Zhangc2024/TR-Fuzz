#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getfloat(float *);

int main(int argc, char const *argv[])
{
	int c;
	float n;
	while ((c = getfloat(&n)) != EOF) {
		printf("%f ", n);
	}
	putchar('\n');

	return 0;
}

/* getfloat: read next float number from the input */
int getfloat(float *n) {
	int c;
	float sign, val, power;

	int getch(void);
	void ungetch(int);

	// skip spaces
	while ((c = getch()) != EOF && !isdigit(c))
		;

	// read a sign
	sign = 1.0;
	if (c == '-' || c == '+') {
		if (c == '-') {
			sign = -sign;
		}

		c = getch();
	}

	// read an integral part
	for (val = 0.0; c != EOF && isdigit(c); c = getch()) {
		val = val * 10.0 + (c - '0');
	}

	if (c == '.') {
		// read a decimal part
		c = getch();
	}

	power = 1.0;
	for (power = 1.0; c != EOF && isdigit(c); c = getch()) {
		val = val * 10.0 + (c - '0');
		power = power * 10.0;
		
	}

	if (c != EOF) {
		ungetch(c);
	}

	// calculate the float number
	*n = sign * val / power;

	return c;
}


#define MAXBUF 10
int buf[MAXBUF];
int bufp = 0;

int getch(void) {
	return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp >= MAXBUF) {
		printf("error: getch buffer overflow");
		exit(1);
	}

	buf[bufp++] = c;
}
