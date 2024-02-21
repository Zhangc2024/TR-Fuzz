#include <stdio.h>

#define MAXLINE 1000 // max input line

int readline(char line[], int maxline); // reads a line and returns its length
void copy(char to[], char from[]); // copies a char array

int main(int argc, char const *argv[])
{
	char line[MAXLINE];
	char longest[MAXLINE];
	int len, max;
	max = 0;
	while ((len = readline(line, MAXLINE)) != 0) {
		if (len > max) {
			copy(longest, line);
			max = len;
		}
	}
	if (max > 0) {
		printf("%s", longest);
	}

	return 0;
}

int readline(char line[], int maxline) {
	int c, i;
	for (i = 0; i < maxline && (c = getchar()) != EOF; ++i) {
		line[i] = c;
		if (c == '\n') {
			++i;
			break;
		}
	}
	line[i] = '\0';
	return i;
}

void copy(char to[], char from[]) {
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}
