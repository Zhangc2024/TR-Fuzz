#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n);
void afree(char *p);

int main(void) {
	return 0;
}

char *alloc(int n) {
	if (allocbuf + ALLOCSIZE - allocp >= 0) {
		allocp += n;
		return allocp - n;
	}
	else return 0;
}

void afree(char *p) {
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE) allocp = p;
}

