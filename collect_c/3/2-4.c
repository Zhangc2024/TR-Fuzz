#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void squeeze(char *s1, char *s2) {
	int i, j, k;
	i = j = 0;
	for (; s1[i] != '\0'; i++) {
		for (k = 0; s2[k] != '\0' && s1[i] != s2[k]; k++)
			;

		if (s2[k] == '\0')
			s1[j++] = s1[i];

	}

	s1[j] = '\0';
}
int main() {
	char s1[] = "abcfcdfe";
	char s2[] = "bcee";
	squeeze(s1, s2);
	if (strcmp(s1, "afdf") == 0)
		putchar('y');

	return EXIT_SUCCESS;
}
