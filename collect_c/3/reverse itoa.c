#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void reverse(char s[]) {
	int i, j, tmp;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = s[i];
	}

}

void itoa(int n, char s[]) {
	int i, sign;

	if ((sign = n) < 0)
		n = -n;

	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);

}
