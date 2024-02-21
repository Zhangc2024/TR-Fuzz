#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\t')
			printf("\\t");
		else if (c == '\b')
			printf("\\b");
		else if (c == '\\')
			printf("\\\\");
		else
			putchar(c);
	}
}
