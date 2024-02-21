#include <assert.h>

void strcat_ptr(char *, char *);

int main(int argc, char const *argv[])
{
	char s[6] = "ab";
	char t[] = "cde";
	strcat_ptr(s, t);

	char *p;
	for (p = s; *p; p++)
		;
	assert((p - s) == 5);
	assert(s[2] == 'c');
	assert(s[3] == 'd');
	assert(s[4] == 'e');

	char s2[2] = "a";
	char t2[] = "";
	strcat_ptr(s2, t2);
	assert(s2[0] == 'a');
	assert(s2[1] == '\0');

	char s3[10] = "";
	char t3[5] = "12345";
	strcat_ptr(s3, t3);
	for (p = s3; *p; p++)
		;
	assert((p - s3) == 5);

	return 0;
}

void strcat_ptr(char *s, char *t) {
	for (; *s; s++)
		;

	for (; *t; s++, t++) {
		*s = *t;
	}

	*s = '\0';
}