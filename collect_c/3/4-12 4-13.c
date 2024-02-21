#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void itoa(int, char*);
void reverse(char *s);

/**
 * Consider corner case -2^31
 */
void itoa(int n, char s[]) {
	static int i = 0;
	int sign;

	if (n / 10 != 0)
		itoa(n / 10, s);
	else if (n < 0)
		s[i++] = '-';

	s[i++] = abs(n % 10) + '0';
	s[i] = '\0';
}

void reverse(char *s) {
	void reverser(char*, int, int);

	reverser(s, 0, strlen(s) - 1);
}

void reverser(char *s, int i, int j) {
	if (i >= j)
		return;

	int tmp;
	tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
	reverser(s, ++i, --j);
}


