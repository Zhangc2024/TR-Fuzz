#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>

/*	Ex 7-1	*/
int main(int argc, char *argv[]) {
	int c;

	if (strcmp(argv[0], "lower") == 0)
		while ((c = getchar()) != EOF)
			putchar(tolower(c));
	else if (strcmp(argv[0], "upper") == 0)
		while ((c = getchar()) != EOF)
			putchar(toupper(c));

	return EXIT_SUCCESS;
}
