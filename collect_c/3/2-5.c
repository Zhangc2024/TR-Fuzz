#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int any(char *s1, char *s2) {
	int i, j;
	i = 0;

	for (; s1[i] != '\0'; i++) {
		j = 0;
		for (; s2[j] != '\0'; j++) {
			if (s2[j] == s1[i])
				return i;
		}

	}
	return -1;
}
int main() {
	char s1[] = "Linux is not Unix";
	char s2[] = "Unix";
	if (any(s1, s2) == 1)
		putchar('y');
	return EXIT_SUCCESS;
}
