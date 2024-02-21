#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/**
 * My solution
 */
int strrindex1(const char *s, const char *t) {
	int i, j, k;
	i = strlen(s) - 1;

	for (; i >= 0; i--) {
		for (k = i, j = strlen(t) - 1; k >= 0 && j >= 0 && s[k] == t[j];
				j--, k--)
			;

		if (k != i && j == -1)
			return k + 1;
	}

	return -1;
}

/**
 * Official Solution1
 */
int strrindex2(const char *s, const char *t) {
	int i, j, k;
	i = 0;

	int pos = -1;
	for (; s[i] != '\0'; i++) {
		for (k = i, j = 0; t[j] != '\0' && s[k] == t[j]; k++, j++)
			;
		if (j > 0 && t[j] == '\0')
			pos = i;

	}
	return pos;
}
/**
 * Official Solution2
 */
int strrindex3(const char *s, const char *t) {
	int i, j, k;
	i = strlen(s) - strlen(t);

	for (; i >= 0; i--) {
		for (j = 0, k = i; t[j] != '\0' && s[k] == t[j]; k++, j++)
			;

		if (j > 0 && t[j] == '\0')
			return i;
	}

	return -1;
}

int main() {
	char *s = "hihihithhhhhhhm";
	char *t = "";

	printf("%d\n", strrindex1(s, t));
	printf("%d\n", strrindex2(s, t));
	printf("%d\n", strrindex3(s, t));
}
