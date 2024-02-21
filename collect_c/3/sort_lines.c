#include <stdio.h>
#include <string.h>

#define MAXLINES	5000
#define MAXLINE 	1000

char *lines[MAXLINES]; // pointers to lines

int readlines(char *lines[], int max);
void qsort(char *lines[], int l, int r);
void writelines(char *lines[], int n);

int main(int argc, char const *argv[])
{
	int nlines;
	if ((nlines = readlines(lines, MAXLINES)) >= 0) {
		qsort(lines, 0, nlines-1);
		writelines(lines, nlines);
		return 0;
	} else {
		printf("error: input is too big to sort\n");
		return 1;
	}
}

int readlines(char *lines[], int max) {
	char **p = lines;
	char line[MAXLINE+1];
	int len;
	char *ptr;
	int readline(char *, int);
	char *alloc(int);

	while ((len = readline(line, MAXLINE+1)) > 0) {
		ptr = alloc(len+1); // extra byte for \0
		if (ptr == NULL || (p - lines) >= max) {
			// not enough space
			return -1;
		}
		
		strcpy(ptr, line);
		*p++ = ptr;
	}

	return (p - lines);
}

int readline(char *line, int max) {
	char *p = line;
	int c;
	while ((c = getchar()) != EOF && c != '\n' && (p - line) < max) {
		*p++ = c;
	}

	*p = '\0';
	return (p - line);
}

#define MAXALLOC 10000
char allocbuf[MAXALLOC];
char *allocp = allocbuf;

char *alloc(int n) {
	if (allocp + n <= allocbuf + MAXALLOC) {
		allocp += n;
		return allocp - n;
	}

	return NULL;
}

#define SWAP(t, x, y) { t tmp; tmp = x; x = y; y = tmp; }

void qsort(char *lines[], int l, int r) {
	int last, i;

	if (l >= r) {
		return;
	}

	SWAP(char *, lines[l], lines[(l + r) / 2]); // put the partition element to the left
	for (last = l, i = l + 1; i <= r; ++i) {
		if (strcmp(lines[i], lines[l]) < 0) {
			last++;
			SWAP(char *, lines[last], lines[i]);
		}
	}
	SWAP(char *, lines[l], lines[last]); // put the partition element back

	qsort(lines, l, last - 1);
	qsort(lines, last + 1, r);
}

void writelines(char *lines[], int n) {
	while (n-- > 0) {
		printf("%s\n", *lines++);
	}
}
