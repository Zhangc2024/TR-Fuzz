#include <stdio.h>
#include <stdlib.h>

#define OUT 0
#define IN 1

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int c, state = OUT;
	long nl, nw, nc;
	nl = nw = nc = 0;

	while ((c = getchar()) != EOF) {
		++nc;
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			if (c == '\n')
				++nl;

		} else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
}
