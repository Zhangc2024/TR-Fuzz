#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 100000

char *linesptr[MAXLINES];

int readlines(char* mem, char *linesptr[], int nlines);
void writelines(char *linesptr[], int nlines);
void qsort(char *linesptr[], int left, int right);

int getline1(char *s, int lim);
char* alloc(int n);
void afree(char *p);

int main() {
	int nlines;
	char mem[ALLOCSIZE];

	if ((nlines = readlines(mem, linesptr, MAXLINES)) >= 0) {
		qsort(linesptr, 0, nlines - 1);
		writelines(linesptr, nlines);
		return 0;
	} else {
		puts("Too big to sort.");
		return 1;
	}
}
int readlines(char mem[], char *linesptr[], int maxlines) {
	int len, nlines;
	char *p, tmp[MAXLEN];
	p = mem;

	nlines = 0;
	while ((len = getline1(tmp, MAXLEN - 1) > 0) && nlines < maxlines
			&& p + len - ALLOCSIZE <= mem) {
		tmp[len - 1] = '\0';
		strcpy(p, tmp);
		linesptr[nlines++] = p;
		p += len;
	}

	if (len <= 0)
		return nlines;
	return -1;
}
void writelines(char *linesptr[], int nlines) {
	while (nlines-- > 0)
		printf("%s\n", *linesptr++);
}

void qsort(char *linesptr[], int l, int r) {
	int i, last;
	void swap(char *v[], int i, int j);

	if (l >= r)
		return;

	swap(linesptr, l, (l + r) / 2);
	last = l;
	for (i = l + 1; i <= r; i++) {
		if (strcmp(linesptr[i], linesptr[l]) < 0)
			swap(linesptr, i, ++last);
	}
	swap(linesptr, last, l);
	qsort(linesptr, l, last - 1);
	qsort(linesptr, last + 1, r);
}

int getline1(char *s, int lim) {
	int i;
	for (i = 0; i < lim - 1 && (s[i] = getchar()) != EOF && s[i] != '\n'; i++)
		;
	if (s[i] == '\n')
		i++;
	s[i] = '\0';
	return i;
}

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char* alloc(int n) {
	if (allocp - allocbuf + n <= ALLOCSIZE) {
		allocp += n;
		return allocp - n;
	}

	puts("Not enough memory.");
	return NULL;
}

void afree(char *p) {
	if (p >= allocbuf && p - allocbuf < ALLOCSIZE)
		allocp = p;
}

void swap(char *v[], int i, int j) {
	char *tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;

}
