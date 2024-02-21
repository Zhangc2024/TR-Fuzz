#include <stdio.h>

#define MAX_LEN 40

int main(int argc, char const *argv[])
{
	int i, c, pc, j, lw;
	char line[MAX_LEN+1];
	char newline[MAX_LEN];
	i = 0;
	lw = 0;
	pc = ' ';
	line[MAX_LEN] = '\0';

	while ((c = getchar()) != EOF) {
		if (i >= MAX_LEN) {
			// max length reached, flushing
			i = 0;
			if (lw > 0) {
				for (j = lw + 1; j < MAX_LEN; ++j) {
					// copy buffered chars after the last word
					newline[i++] = line[j];
					line[j] = '\0';
				}
			}

			printf("%s\n", line);

			// reset line and pointers
			for (j = 0; j < i; ++j) {
				line[j] = newline[j];
			}
			pc = ' ';
			lw = 0;
		}

		if (c == '\n') {
			// flush the line and reset pointers
			line[i] = '\0';
			i = -1;
			lw = 0;

			printf("%s\n", line);
		} else {
			// buffer line characters
			if (c == ' ' && (pc != ' ' && pc != '\n')) {
				// remember the last character index of the last word seen
				lw = i - 1;
			}

			line[i] = c;
		}

		pc = c;
		++i;
	}

	return 0;
}