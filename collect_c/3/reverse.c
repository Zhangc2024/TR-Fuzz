/*
 * K&R Exercise 1-19
 * Write a function `reverse(s)` that reverses the character string s. Use it
 * to write a program that reverses its input a line at a time.
 */

#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int max);
void reverse(char s[], int len);

int main(void)
{
	int length;
	char line[MAXLINE];

	while ((length = get_line(line, MAXLINE)) > 0) {
		reverse(line, length);
		printf("%s", line);
	}
	return 0;
}

int get_line(char s[], int max)
{
	int i;
	int c;
	
	for (i = 0; i < max-1 && (c = getchar()) != EOF && c != '\n'; i++) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

void reverse(char s[], int len)
{
	int i;
	char tmp;

	for (i = 0; i < len / 2; i++) {
		tmp = s[i];
		s[i] = s[(len - 2) - i];
		s[(len - 2) - i] = tmp;
	}
}
