#include <stdio.h>

#define MAXLEN 20

/* write a histogram of word lengths */
main()
{
	int c, i, j, curlen;
	int nchar[MAXLEN];

	for (i = 0; i < MAXLEN; ++i)
		nchar[i] = 0;

	curlen = 0;
	while ((c = getchar()) != EOF)
		if (c == ' ' || c == '\t' || c == '\n') {
			if (curlen >= MAXLEN)
				++nchar[MAXLEN - 1];
			else if (curlen > 0)
				++nchar[curlen-1];
			curlen = 0;
		}
		else
			++curlen;

	for (i = 0; i < MAXLEN; ++i) {
		if (i == MAXLEN - 1)
			printf("%d+:\t", i + 1);
		else
			printf("%d:\t", i + 1);
		for (j = 0; j < nchar[i]; ++j)
			printf("*");
		printf("\n");
	}
}
