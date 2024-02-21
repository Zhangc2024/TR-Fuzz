#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <errno.h>

/*
 * Ex 5-14 5-15 5-16 5-17
 * Some parts are extended and different from the answer book
 * Usage : sort -nfdr +pos1 -pos2
 * n:	Numeric Sort	The string is converted to double
 * f:	Non-Case Sensitive
 * d:	Ignore non-alphanumeric and non-blank chars
 * r:	Print sorted lines in reverse order
 * pos1 and pos2 are all positive integers and pos1 >= pos2. The range of lines for comparing is [pos1, pos2)
 * The default values of pos1 and pos2 are zero.
 * if pos2 is greater than one of the length of two strings being compared, pos2 is cut off to min(strlen(s1), strlen(s2))
 * If pos1 is greater than pos2 in the case pos2 is cut off, pos1 is cut off to zero.
 */

#define MAXLINES 5000
#define MAXLEN	1000

#define NUMR	1
#define DECR	2
#define FOLD	4
#define DIR		8

#define MIN(x, y)	((x<y)?x:y)

static int option = 0; /*	Mask Bits for options	*/
static int pos1 = 0;
static int pos2 = 0;
char *linesptr[MAXLINES]; /*	Lines Buffer storing lines read from stdin	*/

int readlines(char**, int);
void writelines(char**, int, int);
void freelines(char**, int);

void substr(char *dst, char *src);
void resetpos();

void resetpos() {
	pos1 = 0;
	pos2 = 0;
}

void substr(char *dst, char *src) {
	assert(pos1 >= 0 && pos1 <= pos2);

	int bgpos, edpos, i;
	size_t len = strlen(src);

	/*	SetUp Begin and End Positions	*/
	edpos = (!pos2 || pos2 > len) ? len : pos2;
	bgpos = (pos1 <= edpos) ? pos1 : 0;

	/*Copy Array*/
	for (i = 0; bgpos < edpos; i++, bgpos++)
		dst[i] = src[bgpos];
	dst[i] = '\0';
}

void swap(void *v[], int x, int y) {
	void *tmp;
	if (x != y) {
		tmp = v[x];
		v[x] = v[y];
		v[y] = tmp;
	}
}

int numcmp(char *s1, char *s2) {
	double v1, v2, diff;
	char line[MAXLEN];

	substr(line, s1);
	v1 = strtod(line, NULL);
	substr(line, s2);
	v2 = strtod(line, NULL);

	if ((diff = v1 - v2) > 0)
		return 1;
	else if (diff < 0)
		return -1;
	else
		return 0;
}

/*	Compare alphabetic characters, ignoring capital	*/
int charcmp(char *s1, char *s2) {
	assert(pos1 >= 0 && pos2 >= pos1);

	int a, b;
	int edpos, bgpos, i, j;
	size_t len1, len2;
	len1 = strlen(s1);
	len2 = strlen(s2);
	size_t minlen = MIN(len1, len2);
	bool dir = DIR & option;
	bool fold = FOLD & option;

	/*	SetUp Begin and End Positions	*/
	edpos = (!pos2 || pos2 > minlen) ? minlen : pos2;
	bgpos = (pos1 <= edpos) ? pos1 : 0;
	i = j = bgpos;

	a = b = '\0'; /*	The default values of char a and char b. This is used when s1 and s2 are all jumped over in the -d option. 	*/
	do {
		/*	Ignore non-alphanumeric and non-blank characters	*/
		if (dir) {
			for (; i < edpos && !isalnum(s1[i]) && s1[i] != ' '; i++)
				;
			for (; j < edpos && !isalnum(s2[j]) && s2[j] != ' '; j++)
				;
		}

		if (i < edpos) {
			a = (fold) ? tolower(s1[i]) : s1[i];
			i++;
		}
		if (j < edpos) {
			b = (fold) ? tolower(s2[j]) : s2[j];
			j++;
		}
	} while (a == b && i < edpos && j < edpos);

	return a - b;
}

void qsort1(void *v[], int left, int right, int (*comp)(void*, void*)) {
	int i, last, mid = (left + right) / 2;
	void swap(void**, int, int);

	if (left >= right)
		return;

	swap(v, left, mid); /*	Pick Pivot	*/
	last = left;
	for (i = left + 1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, i, ++last);

	swap(v, last, left);
	qsort1(v, left, last - 1, comp);
	qsort1(v, last + 1, right, comp);

}

int readlines(char *lines[], int maxlines) {
	int i = 0;
	char *lineptr;
	size_t n = BUFSIZ;
	ssize_t len;
	for (; i < maxlines && (lineptr = lines[i] = malloc(BUFSIZ)); i++)

	{
		/*	Error Occured or EOF reached	*/
		if ((len = getline(&lines[i], &n, stdin)) == -1) {
			free(lines[i]);
			return i;
		}

		lineptr[len - 1] = '\0';
	}
	return i;
}

void writelines(char *lines[], int nlines, int reverse) {
	int i;

	if (!reverse)
		for (i = 0; i < nlines; i++)
			printf("%s\n", lines[i]);
	else
		for (i = nlines - 1; i >= 0; i--)
			printf("%s\n", lines[i]);
}

void freelines(char *lines[], int nlines) {
	int i;
	for (i = 0; i < nlines; i++)
		free(lines[i]);
}

int readargs(int argc, char *argv[]) {
	int c;
	while (--argc > 0 && ((c = (*++argv)[0]) == '-' || c == '+')) {
		/*	Options	*/
		if (c == '-' && !isdigit((*argv + 1)[0]))
			while ((c = *++argv[0]))
				switch (c) {
				case 'r':
					option |= DECR;
					break;
				case 'n':
					option |= NUMR;
					break;
				case 'f':
					option |= FOLD;
					break;
				case 'd':
					option |= DIR;
					break;
				default:
					perror("Invalid Arguments\n");
					return 1;
					break;
				}
		/*	Pos 2	*/
		else if (c == '-' && (pos2 = strtol(*argv + 1, NULL, 0)) < 0) {
			perror("Position 2 less than zero.\n");
			return 1;
		}
		/*	Pos	1	*/
		else if (c == '+' && (pos1 = strtol(*argv + 1, NULL, 0)) < 0) {
			perror("Position 1 less than zero.\n");
			return 1;
		}
	}
	if (argc != 0 || pos1 > pos2) {
		perror("Usage : sort -dfrn +pos1 -pos2");
		return 1;
	}

	return 0;
}

int main(int argc, char *argv[]) {
	int nlines;/*	Mask bits for reverse and numeric optioin	*/
	int (*comp)(void*, void*); /*	Comparator used in quick sort	*/

	if (readargs(argc, argv) == 1)
		return 1;

	if ((nlines = readlines(linesptr, MAXLINES)) < 0) {
		perror("Input too big to sort.\n");
		return 1;
	}

	/*	Select Comparator	*/
	if (NUMR & option)
		comp = (int (*)(void*, void*)) numcmp;
	else
		comp = (int (*)(void*, void*)) charcmp;

	qsort1((void**) linesptr, 0, nlines - 1, comp);
	writelines(linesptr, nlines, DECR & option);

	freelines(linesptr, nlines);
	resetpos();
	return EXIT_SUCCESS;

}
