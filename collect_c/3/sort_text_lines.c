#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
    int nlines; /* number of input lines read */

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {

        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {

        printf("error: input too big to sort\n");
        return 1;
    }

    return 0; //return SUCCESS
}


#define MAXLEN 1000 /* max length of any input line */
int _getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    
    nlines = 0;
    while ((len = _getline(line, MAXLEN)) > 0) {
        
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }

    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
    {
        printf("%s\n", lineptr[i]);
    }
}

int _getline(char * line, int maxlen)
{
    int i, c;

    for (i = 0; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {

        allocp += n;
        return allocp - n;

    } else {
        
        return 0;
    }
}

void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}


void swap(char *v[], int i, int j);

/* qsort : sort v[left] ... v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    
    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */

    swap(v, left, (left + right)/2);
    
    last = left;

    for (i = left + 1; i <= right; i++) /* v[left] is the pivot */
    {
        if (strcmp(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    } /* by the end, all values smaller than the pivot and which resides after pivot are moved to the left of pivot */

    /* the smallest value which is in position last is moved to first position and pivot is moved to fill the gap left by the smallest value */
    swap(v, left, last); 
    
    /* the usual recursive call to quick sort */
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


















