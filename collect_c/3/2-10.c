#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int lower(char c) {
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
int main() {
	char x = 'X';
	char y = 'y';
	putchar(lower(x));
	putchar(lower(y));
	return EXIT_SUCCESS;
}
