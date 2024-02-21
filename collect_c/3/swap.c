#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "swap.h"

int main(int argc, char const *argv[])
{
	int x = 5, y = 10;

	SWAP(int, x, y);
	assert(x == 10);
	assert(y == 5);

	char c1 = 'a', c2 = 'b';
	SWAP(char, c1, c2);
	assert(c1 == 'b');
	assert(c2 == 'a');

	char s[] = "car";
	SWAP(char, s[0], s[1]);
	SWAP(char, s[1], s[2]);
	assert(strcmp(s, "arc") == 0);

	return 0;
}