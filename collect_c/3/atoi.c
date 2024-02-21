#include <stdio.h>
#include <ctype.h>

#define MAX_INPUT 20

int atoi(char s[]);

int main(int argc, char const *argv[])
{
	int c, i;
	char input[MAX_INPUT+1];
	i = 0;

	while ((c = getchar()) != EOF && i < MAX_INPUT) {
		input[i++] = c;
	}
	input[i] = '\0';

	printf("%d\n", atoi(input));

	return 0;
}

/* atoi: convert s to integer */
int atoi(char s[]) {
	int i, n, sign;

	n = 0;

	// skip whitespaces
	for (i = 0; isspace(s[i]); ++i) {}

	// skip sign
	sign = s[i] == '-' ? -1 : 1;
	if (s[i] == '-' || s[i] == '+') {
		++i;
	}

	for (; s[i] >= '0' && s[i] <= '9'; ++i) {
		n = 10 * n + (s[i] - '0');
	}

	return sign * n;
}