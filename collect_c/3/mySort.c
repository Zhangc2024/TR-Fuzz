#include <stdio.h>
#include <string.h>
#include "alloc.h"

#define MAXLINES 5000       /* max #lines to be sorted */

char *lineptr[MAXLINES];    /* pointers to text lines */
int readlines(char *lineptr[], int nlines);
void writelines_2(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main() {
    int nlines;             /* number of input lines read */
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines_2(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000         /* max length of any input line */
int myGetline(char *, int);
char *alloc(int);
void swap(char *v[], int i, int j);

/* readlines:   read input lines */
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = myGetline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

/* writelines: write output lines */
void writelines_1(char *lineptr[], int nlines) {
    int i;
    printf("The sorted strings are:\n");
    for (i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

void writelines_2(char *lineptr[], int nlines) {
    printf("The sorted strings are:\n");
    while (nlines-- > 0) {
        printf("%s\n", *lineptr++);
    }
}

/* getline: read a line into s, return length */
int myGetline(char s[], int lim) {
    int c, i;
    
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right) {
    int i, last;
    
    if (left >= right) {        /* do nothing if array contains */
        return;                 /* fewer than two elements      */    
    }
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0){
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}