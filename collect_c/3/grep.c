#include <stdio.h>
#include <string.h>

#define MAXLINE 	1000
#define MAXPATTERN 	32

int readline(char line[], int max);
int strindex(char source[], char str[]);

int main(int argc, char const *argv[])
{
	char line[MAXLINE+1];
	char pattern[MAXPATTERN];

	if (argc < 2) {
		printf("pattern argument required\n");
		return 1;
	}

	strcpy(pattern, argv[1]);

	while(readline(line, MAXLINE) > 0) {
		if (strindex(line, pattern) >= 0) {
			printf("%s\n", line);
		}
	}

	return 0;
}

int readline(char line[], int max) {
	int c, i;

	i = 0;
	while ((c = getchar()) != EOF && i < max && c != '\n') {
		line[i++] = c;
	}
	line[i] = '\0';
	return i;
}

int strindex(char source[], char str[]) {
	int i, j;
	for (i = 0; source[i] != '\0'; ++i) {
		for (j = 0; str[j] != '\0' && source[i+j] == str[j]; ++j)
			;
		if (j > 0 && str[j] == '\0') {
			return i;
		}
	}

	return -1;
}
