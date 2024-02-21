#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

void strcpy1(char *s1, char *s2);
int strcmp1(char *s1, char *s2);
void strcat1(char *s, char *t);
int strend(char *s, char *t);
void strncpy1(char *s, char *t, int n);
void strncat1(char *s, char *t, int n);
int strncmp1(char *s, char *t, int n);

void strcpy1(char *s1, char *s2) {
	while ((*s1++ = *s2++))
		;
}

int strcmp1(char *s1, char *s2) {
	for (; *s1 && *s1 == *s2; s1++, s2++)
		;

	return (*s1 - *s2);
}

void strcat1(char *s, char *t) {
	strcpy1(s + strlen(s), t);
}

int strend(char *s, char *t) {
	return strlen(s) >= strlen(t)
			&& (strcmp(s + strlen(s) - strlen(t), t) == 0) ? 1 : 0;
}

void strncpy1(char *s, char *t, int n) {
	while (*t && --n >= 0)
		*s++ = *t++;

	while (--n >= 0)
		*s++ = '\0';
}

void strncat1(char *s, char *t, int n) {
	strncpy1(s + strlen(s), t, n);
}

int strncmp1(char *s, char *t, int n) {
	for (; n > 0 && *t && *s == *t; n--, s++, t++)
		;

	return (n == 0) ? 0 : (*s - *t);

}
int main() {
	char *s1 = "Hello Mr";
	char *s2 = "Hello World";
	printf("%d", strncmp1(s1, s2, 5));
	printf("%d", strncmp1(s1, s2, 6));
	printf("%d", strncmp1(s1, s2, 4));
	printf("%d", strncmp1(s1, s2, 7));
	printf("%d", strncmp1(s1, s2, 100000));
	printf("%d", strncmp1("Hello World", s2, 11));
	printf("%d", strncmp1("Hello World", s2, 20));

}
