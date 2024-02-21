#include <stdio.h>
#include <assert.h>

int strcmp_ptr(char *, char *);

int main(int argc, char const *argv[])
{
	char s1[] = "aabbc";
	char s2[] = "aabcd";

	assert(strcmp_ptr(s1, s2) < 0);
	assert(strcmp_ptr(s2, s1) > 0);

	char s3[] = "aabbc";

	assert(strcmp_ptr(s1, s3) == 0);

	char s4[] = "aabb";

	assert(strcmp_ptr(s4, s1) < 0);
	assert(strcmp_ptr(s1, s4) > 0);

	return 0;
}

int strcmp_ptr(char *s1, char *s2) {
	for (; *s1 == *s2; s1++, s2++) {
		if (*s1 == '\0') {
			return 0;
		}
	}

	return *s1 - *s2;
}