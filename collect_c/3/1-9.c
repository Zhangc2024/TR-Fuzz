#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int c;
	int lastc = 'a';
	while ((c = getchar()) != EOF) {
		if (c != ' ' || lastc != ' ')
			putchar(c);
		lastc = c;
	}
}
