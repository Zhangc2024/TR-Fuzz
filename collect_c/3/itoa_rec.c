#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAXLEN 12

void itoa_rec(int n, char s[]);

int main(int argc, char const *argv[])
{
	char s[MAXLEN];

	itoa_rec(123, s);
	assert(strcmp(s, "123") == 0);

	itoa_rec(12647, s);
	assert(strcmp(s, "12647") == 0);

	itoa_rec(-5768492, s);
	assert(strcmp(s, "-5768492") == 0);

	itoa_rec(-1, s);
	assert(strcmp(s, "-1") == 0);

	itoa_rec(0, s);
	assert(strcmp(s, "0") == 0);

	itoa_rec(1843273840, s);
	assert(strcmp(s, "1843273840") == 0);

	// minimum integer value
	itoa_rec(1 << 31, s);
	assert(strcmp(s, "-2147483648") == 0);
}

void itoa_rec(int n, char s[]) {
	int _itoa(int, char[]);
	int i = _itoa(n, s);
	s[i] = '\0';
}

int _itoa(int n, char s[]) {
	int i = 0;
	int d;

	if (n/10) {
		i = _itoa(n/10, s);
	} else if (n < 0) {
		s[i++] = '-';
	}

	d = n%10; // to handle minimum integer value properly
	if (d < 0) {
		d = -d;
	}
	
	s[i] = d + '0';
	return i+1;
}
