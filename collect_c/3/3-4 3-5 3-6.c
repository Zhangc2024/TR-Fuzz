#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void reverse(char[]);

void itob(int n, char s[], int b) {
	int i, j, sign;

	if ((sign = n) < 0)
		n = -n;

	i = 0;
	do {
		s[i++] = (j = n % b) < 10 ? n % b + '0' : n % b - 10 + 'a';
	} while ((n /= b) > 0);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);

}

void itoa(int n, char s[], int wid) {
	int i, sign;

	sign = n;
	i = 0;
	do {
		s[i++] = abs(n % 10) + '0';
	} while ((n /= 10) != 0);

	if (sign < 0)
		s[i++] = '-';
	while (i < wid)
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s);

}

void reverse(char s[]) {
	int i, j, tmp;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = s[i];
	}

}
