#include <stdio.h>

char lower(char c);

int main(void) {
	printf("%c\n", lower('A'));

	return 0;
}

/* convert c to lower case; ASCII only */
char lower(char c) {
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}
