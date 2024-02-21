#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
	int i, lim, c;
	char s[100];
	bool instr = true;

	while (instr) {
		if (i >= lim - 1)
			instr = false;
		else if ((c = getchar()) == EOF)
			instr = false;
		else if (c == '\n')
			instr = false;
		else
			s[i++] = c;

	}
}
