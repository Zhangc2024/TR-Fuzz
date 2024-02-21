#include <stdio.h>

#define IN 	1
#define OUT 0

int main(int argc, char const *argv[])
{
	int nc, nw, nl, c, state;
	nc = nw = nl = 0;
	state = OUT;
	
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n') {
			++nl;
		}
		if (c == '\n' || c == ' ' || c == '\t') {
			state = OUT;
		} else if (state == OUT) {
			state = IN;
			++nw;
		}
	}

	printf("characters: %d, words: %d, lines: %d", nc, nw, nl);

	return 0;
}