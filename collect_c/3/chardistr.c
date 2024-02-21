#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c, i, j;
	int chr[26];
	for (i = 0; i < 26; ++i) {
		chr[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z') {
			++chr[c - 'a'];
		} else if (c >= 'A' && c <= 'Z') {
			++chr[c - 'A'];
		}
	}

	for (i = 0; i < 26; ++i) {
		printf("%c\t", 'a' + i);
		for (j = 0; j < chr[i]; ++j) {
			printf("-");
		}
		printf("\n");
	}

	return 0;
}