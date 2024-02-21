#include <stdio.h>

#define MAXLEN 16

int main(int argc, char const *argv[])
{
	int c, i, j;
	int lenwords[MAXLEN];
	for (i = 0; i < MAXLEN; ++i) {
		lenwords[i] = 0;
	}

	i = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			// word ended
			if (i > 0) {
				
				if (i >= MAXLEN) {
					i = MAXLEN - 1;
				}

				++lenwords[i];
				i = 0;
			}
		} else {
			++i;
		}
	}

	for (i = 1; i < MAXLEN; ++i) {
		printf("%2d\t", i);
		for (j = 0; j < lenwords[i]; ++j) {
			printf("-");
		}
		printf("\n");
	}

	return 0;
}