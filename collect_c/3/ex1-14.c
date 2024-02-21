#include <stdio.h>

#define MAXCHAR 256

main()
{
	int c, i, j;
	int chars[MAXCHAR];

	for (i = 0; i < MAXCHAR; i++) {
		chars[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c < MAXCHAR)
			++chars[c];
	}

	for (i = 0; i < MAXCHAR; i++) {
		if (chars[i] > 0) {
			printf("'");
			if (i == '\t')
				printf("\\t' ");
			else if (i == '\n')
				printf("\\n' ");
			else
				printf("%c'  ", i);
			for (j = 0; j < chars[i]; j++) {
				printf("*");
			}
			printf("\n");
		}
	}

}
