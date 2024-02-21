#include <assert.h>

int strlen_ptr(char *);

int main(int argc, char const *argv[])
{
	char s[] = "hello C";
	assert(strlen_ptr(s) == 7);

	char *p = "pointer";
	assert(strlen_ptr(p) == 7);

	assert(strlen_ptr("string literal") == 14);

	return 0;
}

/* strlen_ptr: strlen pointer version */
int strlen_ptr(char *s) {
	char *p = s;
	while (*p) {
		p++;
	}

	return p - s;
}