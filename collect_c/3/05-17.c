#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUMERIC	1		/* numeric sort */
#define DECR	2		/* sort in decreasing order */
#define FOLD	4		/* fold upper and lower cases */
#define DIR		8		/* fold upper and lower cases */

#define LINES	100		/* max # of lines to be sorted */
#define MAXLEN	1000

int charcmp(char *, char *);
int numcmp(char *, char *);
int readlines(char *lineptr[], int maxlines);
void qsort(void *v[], int left, int right, int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines, int decr);
void readargs(int argc, char *argv[]);
void error(char *);

char option = 0;
int pos1 = 0;
int pos2 = 0;

/* sort input lines */
main(int argc, char *argv[])
{
	char *lineptr[LINES];	/* pointers to text lines */
	int nlines;			/* number of input lines read */
	int rc = 0;

	readargs(argc, argv);
	
	if ((nlines = readlines(lineptr, LINES)) > 0) {
		if (option & NUMERIC)
			qsort((void **) lineptr, 0, nlines - 1,
				(int(*)(void *, void *)) numcmp);
		else
			qsort((void **) lineptr, 0, nlines - 1,
				(int(*)(void *, void *)) charcmp);
		writelines(lineptr, nlines, option & DECR);
	} else {
		printf("input too big to sort\n");
		rc = -1;
	}
	return rc;
}

void readargs(int argc, char *argv[])
{
	int c;
	int atoi(char *);
	
	while (--argc > 0 && (c = (*++argv)[0]) == '-' || c == '+') {
		if (c == '-' && !isdigit(*(argv[0]+1)))
			while (c == *++argv[0])
				switch (c){
					case 'd':
						option |= DIR;
						break;
					case 'f':
						option |= FOLD;
						break;
					case 'n':
						option |= NUMERIC;
						break;
					case 'r':
						option |= DECR;
						break;
					default:
						printf("sort: illegal option %c\n", c);
						error("Usage: sort -dfnr [+pos1] [-pos2]");
						break;
				}
		else if (c == '-')
			pos2 = atoi(argv[0] + 1);
		else if ((pos1 = atoi(argv[0]+1)) < 0)
			error("Usage: sort -dfnr [+pos1] [-pos2]");
	}
	if (argc || pos1 > pos2)
		error("Usage: sort -dfnr [+pos1] [-pos2]");
}


void qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);
	
	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	
	for (i = left + 1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1, comp);
	qsort(v, last+1, right, comp);
}

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	
	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int decr)
{
	int i;
	
	if (decr)	/* print in decreasing order */
		for (i = nlines - 1; i >= 0; i--)
			printf("%s\n", lineptr[i]);
	else		/* print in increasing order */
		for (i = 0; i < nlines; i++)
			printf("%s\n", lineptr[i]);
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

void swap(void *v[], int i, int j)
{
	void *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void error(char *s)
{
	printf ("error: %s", s);
}
