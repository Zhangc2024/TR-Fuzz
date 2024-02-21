#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAXLEN 100

void reverse_rec(char s[]);

int main(int argc, char const *argv[])
{
	char s[MAXLEN];

	strcpy(s, "321");
	reverse_rec(s);
	assert(strcmp(s, "123") == 0);

	strcpy(s, "abcdefg");
	reverse_rec(s);
	assert(strcmp(s, "gfedcba") == 0);

	strcpy(s, "0");
	reverse_rec(s);
	assert(strcmp(s, "0") == 0);

	strcpy(s, "-2");
	reverse_rec(s);
	assert(strcmp(s, "2-") == 0);

	return 0;
}

/* reverse_rec: reverse a string in place using recursive approach */
void reverse_rec(char s[]) {
	void _reverse(char[], int, int);
	int i;
	for (i = 0; s[i] != '\0'; ++i)
		;
	_reverse(s, 0, i-1);
}

void _reverse(char s[], int l, int r) {
	char t;

	if (l >= r) {
		return;
	}

	t = s[l];
	s[l] = s[r];
	s[r] = t;

	_reverse(s, l+1, r-1);
}