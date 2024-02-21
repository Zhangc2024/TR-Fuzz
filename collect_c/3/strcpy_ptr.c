#include <assert.h>

void strcpy_ptr(char *t, char *s);

int main(int argc, char const *argv[])
{
	char s1[] = "abcd";
	char s2[] = "defghi";

	strcpy_ptr(s2, s1);
	assert(s2[0] == 'a');
	assert(s2[1] == 'b');
	assert(s2[2] == 'c');
	assert(s2[3] == 'd');
	assert(s2[4] == '\0');

	return 0;
}

void strcpy_ptr(char *t, char *s) {
	while ((*t++ = *s++))
		;
}