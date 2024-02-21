#include <assert.h>

int strend(char *, char *);

int main(int argc, char const *argv[])
{
	assert(strend("abcdef", "def") == 1);
	assert(strend("abcdef", "de") == 0);
	assert(strend("abcdef", "") == 0);
	assert(strend("", "abc") == 0);
	assert(strend("abc", "abc") == 1);
	assert(strend("abc", "c") == 1);
	
	return 0;
}

int strend(char *s, char *t) {
	char *ps, *pt;
	for (ps = s; *ps; ps++)
		;
	for (pt = t; *pt; pt++)
		;

	if ((pt - t) > (ps - s) || pt == t) {
		// t is longer than s or t is zero string
		return 0;
	}

	for (; *ps == *pt && pt > t; ps--, pt--)
		;

	if (*ps == *pt && pt == t) {
		return 1;		
	}

	return 0;
}