#include <stdio.h>

int lens(const char s[]);

int main(void) {
	printf("%d\n", lens("teste123"));

	return 0;
}

/* strlen: return the length of s */
int lens(const char s[]) {
	int i;

	i = 0;
	while (s[i] != '\0')
		++i;

	return i;
}
