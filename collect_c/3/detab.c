#include <stdio.h>

#define TAB_SIZE 4

int main(int argc, char const *argv[])
{
	int c, i, j;

	i = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			i = -1;
		}

		if (c == '\t') {
			for (j = TAB_SIZE - (i % TAB_SIZE); j > 0; --j) {
				// printing spaces until the next tab stop
				putchar(' ');
				++i;
			}
		} else {
			putchar(c);
			++i;
		}
	}
	return 0;
}