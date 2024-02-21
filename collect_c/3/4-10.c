#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define NUMBER 0

int getop(char s[]) {
	static char line[BUFSIZ];
	static int i = 0;
	int getline1(char[], size_t);
	int c, j;

	if (!line[i]) {
		if (getline1(line, BUFSIZ))
			return EOF;
		i = 0;
	}

	/* Consume white spaces */
	for (; line[i] == ' ' || line[i] == '\t'; i++)
		;

	c = line[i];
	if (!isdigit(c)) /*Whehter next is an operation */
		return line[i++];
	if (isdigit(c)) /*Whether next is a digit */
		for (j = 0; isdigit(c = line[i]); i++, j++) /*Get Integer Part */
			s[j] = c;
	if (c == '.') /*Whether it has a fraction part */
		for (; isdigit(c = line[i]); i++, j++)
			s[j] = c;

	s[j] = '\0';
	return NUMBER;
}

int getline1(char dst[], size_t max) {
	int c, i;

	for (i = 0; i < max - 1 && (c = getchar()) != '\n' && c != EOF; i++)
		dst[i] = c;

	if (c == '\n')
		dst[i++] = c;
	dst[i] = '\0';

	return i;
}

int main() {

}
