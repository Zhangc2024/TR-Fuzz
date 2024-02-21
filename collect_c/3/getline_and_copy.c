#include <stdio.h>
#include <stdlib.h>
#define MAXLINE  1000

int agetline(char*, int);

void copy(char tg[], char src[]);

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int len = 0;
	int max = 0;
	char line[MAXLINE];
	char longest[MAXLINE];

	while ((len = agetline(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}

	}

	if (max > 0)
		printf("%s", longest);

	return EXIT_SUCCESS;
}

int agetline(char line[], int max) {
	int c, i;

	for (i = 0; i < max - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
		line[i] = c;
	}

	if (c == '\n') {
		line[i++] = c;
	}

	line[i] = 0;

	return i;
}

void copy(char tg[], char src[]) {
	int i = 0;
	while ((tg[i] = src[i]) != 0){
		i++;
	}

}
