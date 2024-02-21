#include <stdio.h>

/* copy input to ouput 1st version */
main() {
	int c;

	while((c = getchar()) != EOF)
		putchar(c);
}
