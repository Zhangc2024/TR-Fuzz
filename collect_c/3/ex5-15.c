#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NUMERIC 1 /* numeric sort */
#define DECR    2 /* sort in decreasing order */
#define FOLD    4 /* fold upper and lower cases */
#define LINES   100 /* max # of lines to be sorted */

int charcmp(const char *, const char *);
int numcmp(const char *, const char *);
int readlines(char *lineptr[], int maxlines);

void _qsort(void *v[], int left, int right, int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines, int order);

static char option = 0;

int main(int argc, char *argv[])
{
  char *lineptr[LINES]; /* pointers to text lines */
  int nlines;           /* number of input lines read */
  int c, rc = 0;

  while (--argc > 0 && (*++argv)[0] == '-') {
    while ((c = *++argv[0])) {
      switch(c) {
      case 'f': /* fold upper and lower cases */
          option |= FOLD;
          break;
      case 'n': /* numeric sort */
          option |= NUMERIC;
          break;
      case 'r': /* sort in decreasing order */
          option |= DECR;
          break;
      default:
          printf("sort: illegal option %c\n", c);
          argc = 1;
          rc = -1;
          break;
      }
    }
  }


  if (argc) {
    printf("Usage: sort -fnr \n");
  } else {

    if ((nlines = readlines(lineptr, LINES)) > 0) {
      if (option & NUMERIC) {
        _qsort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *)) numcmp);
      } else if (option & FOLD) {
        _qsort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *)) charcmp);
      } else {
        _qsort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *)) strcmp);
      }

      writelines(lineptr, nlines, option & DECR);
    } else {
      printf("input too big to sort \n");
      rc = -1;
    }
  }

  return rc;
}

/* qsort: sort v[left]...v[right] into increasing order */
void _qsort (void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) { /* do nothing if array contains fewer than two elements */

        return;
    }

    swap (v, left, (left + right)/2);
    last = left;

    for (i = left + 1; i <= right; i++)
    {
        if ((*comp)(v[i], v[left]) < 0) {

            swap(v, ++last, i);
        }        
    }
    swap(v, left, last);
    _qsort(v, left, last-1, comp);
    _qsort(v, last+1, right, comp);
}


/* charcmp: return < 0 if s < t, 0 if s == t, >0 if s > t */
int charcmp(const char *s, const char *t) {

  for ( ; tolower(*s) == tolower(*t); s++, t++) {
    if (*s == '\0') {
      return 0;
    }
  }

  return tolower(*s) - tolower(*t);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp (const char *s1, const char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2) {
        return -1;
    } else if (v1 > v2) {
        return 1;
    } else {
        return 0;
    }
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
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

void writelines(char *lineptr[], int nlines, int decr) 
{
    int i;

    if (decr) { /* print in decreasing order */
        for (i = nlines - 1; i >= 0; i--) {
            printf("%s\n", lineptr[i]);
        }
    } else { /* print in increasing order */
        for (i = 0; i < nlines; i++) {
            printf("%s\n", lineptr[i]);
        }
    }
}

