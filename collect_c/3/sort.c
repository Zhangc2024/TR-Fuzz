#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main(void) {
	return 0;
}

#define MAXLEN 1000
int lineget(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines) {
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = lineget(line,MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len=1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines) {
	int i;
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

void qsort(char *v[], int left, int right) {
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right) return;

	swap(v, left, (left + right)/2);
	last = left;
	for (i = left +1; i <= right; i++)
		swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

void swap(char *v[], int i, int j) {
	char *tmp;
	tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}
