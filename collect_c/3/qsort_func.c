#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXVALS 1000000
char *vals[MAXVALS];

int readvals(char **vals, int max);
void qsort_f(void **arr, int l, int r, int (*comp)(void *, void *), int);
void printvals(char **vals, int n);
int numcmp(const char *, const char *);

int main(int argc, char const *argv[])
{
	int nvals;
	int numeric = 0, order = 1;
	int c;

	while (--argc && (*++argv)[0] == '-') {
		while((c = *++argv[0])) {
			switch (c) {
				case 'n':
					numeric = 1;
					break;
				case 'r':
					order = -1;
					break;
				default:
					printf("unknown options %c\n", c);
					argc = 0;
					break;
			}
		}
	}

	if (argc != 0) {
		printf("usage: qsort_func -n");
		exit(1);
	}

	if ((nvals = readvals(vals, MAXVALS)) > 0) {
		qsort_f((void **)vals, 0, nvals-1, (int (*)(void *, void *))(numeric ? numcmp : strcmp), order);
		printvals(vals, nvals);
	} else {
		printf("error: no input or input is too big");
		exit(1);
	}

	return 0;
}

int numcmp(const char *s1, const char *s2) {
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	return v1 < v2 ? -1 : v1 == v2 ? 0 : 1;
}

#define SWAP(t, x, y) { t tmp; tmp = x; x = y; y = tmp; }

void qsort_f(void **arr, int l, int r, int (*comp)(void *, void *), int order) {
	int last, i;
	if (l >= r) {
		return;
	}

	SWAP(void *, arr[l], arr[(l + r) / 2]);
	for (last = l, i = l + 1; i <= r; ++i) {
		if (comp(arr[i], arr[l]) * order < 0) {
			++last;
			SWAP(void *, arr[i], arr[last]);
		}
	}
	SWAP(void *, arr[l], arr[last]);
	qsort_f(arr, l, last - 1, comp, order);
	qsort_f(arr, last + 1, r, comp, order);
}

void printvals(char **vals, int n) {
	while (n-- > 0) {
		printf("%s ", *vals++);
	}
}

#define MAXVAL 12

int readvals(char **vals, int max) {
	char **ptr = vals;
	char val[MAXVAL+1];
	char *p;
	int len;

	int readval(char *val, int max);
	char *alloc(int n);

	while ((len = readval(val, MAXVAL)) > 0 && (ptr - vals) < max) {
		if ((p = alloc(len+1)) != NULL) {
			strcpy(p, val);
			*ptr++ = p;	
		}
	}

	return (ptr - vals);
}

int readval(char *val, int max) {
	char *p = val;
	int c;
	while ((c = getchar()) != EOF && c != '\n' && c != '\t' && c != ' ' && (p - val) < max) {
		*p++ = c;
	}

	*p = '\0';
	return (p - val);
}


#define MAXALLOC 4000000
char buf[MAXALLOC];
char *bufp = buf;

char *alloc(int n) {
	if (bufp + n <= buf + MAXALLOC) {
		bufp += n;
		return bufp - n;
	} else {
		return 0;
	}
}
