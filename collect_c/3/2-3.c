#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int htoi(char *s) {
	int i, n;
	i = n = 0;
	bool inhex = true;

	if (s[i] == '0') {
		if (s[++i] == 'x' || s[i] == 'X')
			i++;
	}

	for (; inhex; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			n = 16 * n + s[i] - '0';
		else if (s[i] >= 'a' && s[i] <= 'f')
			n = 16 * n + 10 + s[i] - 'a';
		else if (s[i] >= 'A' && s[i] <= 'F')
			n = 16 * n + 10 + s[i] - 'A';
		else
			inhex = false;
	}

	return n;
}

int main() {
	char *s = "0XfF1Avv";
	int x = 0xff1a;
	if (x == htoi(s))
		putchar('y');
}
