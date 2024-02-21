#include <stdio.h>
#include <stdlib.h>

#define MAXINT 11

void printd(int n);

int main(int argc, char const *argv[])
{
	int i, c;
	char s[MAXINT];

	i = 0;
	while ((c = getchar()) != EOF) {
		s[i++] = c;
	}
	s[i] = '\0';

	printd(atoi(s));
	putchar('\n');

	return 0;
}

/* printd: prints an integer in a recursion way */
void printd(int n) {
	if (n < 0) {
		n = -n;
		putchar('-');
	}

	if (n / 10) {
		printd(n / 10);
	}

	putchar((n % 10) + '0');
}