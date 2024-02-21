#include <stdio.h>

#define MAX_INPUT 64

int htoi(char s[]);

int main(int argc, char const *argv[])
{
	int i, c;
	char s[MAX_INPUT+1];

	i = 0;
	while ((c = getchar()) != EOF && i < MAX_INPUT) {
		s[i++] = c;
	}
	s[i] = '\0';

	printf("%d\n", htoi(s));

	return 0;
}

/* htoi: convert hexadecimal string s to integer */
int htoi(char s[]) {
	int i, n, p;

	i = 0;
	n = 0;

	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
		// truncate hex prefix
		i = 2;
	}

	while (s[i] != '\0') {
		if (s[i] >= '0' && s[i] <= '9') {
			p = s[i] - '0';
		} else if (s[i] >= 'a' && s[i] <= 'f') {
			p = s[i] - 'a' + 10;
		} else if (s[i] >= 'A' && s[i] <= 'F') {
			p = s[i] - 'A' + 10;
		} else {
			break;
		}

		n = 16 * n + p;
		++i;
	}

	return n;
}