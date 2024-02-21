#include <assert.h>

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int);
void afree(char *);

int main(int argc, char const *argv[])
{
	char *s1 = alloc(10);
	assert(s1 != 0);

	char *s2 = alloc(20);
	assert(s2 != 0);

	assert(alloc(ALLOCSIZE) == 0);

	assert(s2 > s1);

	afree(s2);
	afree(s1);

	assert(allocp == allocbuf);

	return 0;
}

char *alloc(int n) {
	if (allocp + n <= allocbuf + ALLOCSIZE) {
		allocp += n;
		return allocp - n;
	}

	return 0;
}

void afree(char *p) {
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
		allocp = p;
	}
}
