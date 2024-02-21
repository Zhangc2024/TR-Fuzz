#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAXLEN 128
#define ALPHABET "0123456789abcdef"

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(int argc, char const *argv[])
{
	char s[MAXLEN+1];
	
	itob(255, s, 16);
	assert(strcmp(s, "ff") == 0);

	itob(0, s, 16);
	assert(strcmp(s, "0") == 0);

	itob(50, s, 16);
	assert(strcmp(s, "32") == 0);

	itob(0xff11cc, s, 16);
	assert(strcmp(s, "ff11cc") == 0);

	itob(49256, s, 2);
	assert(strcmp(s, "1100000001101000") == 0);

	return 0;
}

/* itob: convert an integer into a base b character representation in the string s */
void itob(int n, char s[], int b) {
	assert(b <= 16);

	int i, r;
	i = 0;
	do {
		r = n % b;
		s[i++] = ALPHABET[r];
		n = n/b;
	} while(n != 0);
	s[i] = '\0';
	reverse(s);
}

/* reverse: reverse characters in the string s */
void reverse(char s[]) {
	int i, j, n;
	char c;
	for (n = 0; s[n] != '\0'; ++n)
		;

	for (i = 0, j = n-1; i < j; ++i, --j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}