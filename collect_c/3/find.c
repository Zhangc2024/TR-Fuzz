/* usage: find -nx pattern */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

int readline(char *line, int max);

int main(int argc, char const *argv[])
{
	char line[MAXLINE];
	int c, linenum = 0;
	int number = 0, except = 0;

	// read optional parameters
	while (--argc > 0 && (*++argv)[0] == '-') {
		while ((c = *++argv[0])) {
			switch (c) {
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("find: illegal option %c\n", c);
					argc = 0;
					break;
			}
		}
	}

	if (argc != 1) {
		printf("usage: find -n -x pattern");
		exit(1);
	}

	while (readline(line, MAXLINE) > 0) {
		linenum++;
		if ((strstr(line, *argv) != NULL) != except) {
			if (number) {
				printf("%d: ", linenum);
			}
			printf("%s\n", line);
		}
	}

	return 0;
}

int readline(char *line, int max) {
	char *p = line;
	int c;
	while ((c = getchar()) != EOF && c != '\n' && (p - line) < max) {
		*p++ = c;
	}
	*p = '\0';
	return p - line;
}
