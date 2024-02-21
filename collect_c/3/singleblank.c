#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c, pc;
	pc = -1;
	while ((c = getchar()) != EOF) {
		if (c == ' ' && pc == ' ') {
			continue;
		}
		putchar(c);
		pc = c;
	}
	return 0;
}