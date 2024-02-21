/* Exercise 5-13. Write the program tail, which prints the last n lines of its
 * input. By default, n is 10, let us say, but it can be changed by an optional
 * argument, so that
 *  
 *      tail -n
 *
 *  prints the last n lines. The program should behave rationally no matter how
 *  unreasonable the input or the value of n. Write the program so it makes the
 *  best use of available storage; lines should be stored as in the sorting program
 *  of Section 5.6, not in a two-dimensional array of fixed size.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_LINES 10 /* default # of lines to print */
#define LINES 100 /* max # of lines to print */
#define MAXLEN 100 /* max length of an input line */

void _error(char *);
int _getline(char *, int);

/* print last n lines of the input */
int main(int argc, char *argv[])
{
    char *p;
    char *buf; /* pointer to large buffer */
    char *bufend; /* end of the buffer */
    char line[MAXLEN]; /* current input line */
    char *lineptr[LINES]; /* pointers to lines read */
    int first, i, last, len, n, nlines;

    if (argc == 1) { /* no argument present */
        
        n = DEFAULT_LINES; /* use default # of lines */

    } else if (argc == 2 && (*++argv)[0] == '-') {

        n = atoi(argv[0] + 1);

    } else {
        
        _error("usage: tail [-n]");
    }

    if (n < 1 || n > LINES) { /* unreasonable value for n ? */
        n = LINES;
    }

    for (i = 0; i < LINES; i++)
    {
        lineptr[i] = NULL;
    }

    if ((p = buf = malloc(LINES * MAXLEN)) == NULL) {

        _error("tail: cannot allocate buf");
    }

    bufend = buf + LINES * MAXLEN;

    last = 0; /* index of last line reed */
    nlines = 0; /* number of lines read */

    while ((len = _getline(line, MAXLEN)) > 0) {
        
        if (p + len + 1 >= bufend) {
            p = buf; /* buffer wrap around */
        }

        lineptr[last] = p;
        strcpy(lineptr[last], line);
        
        if (++last >= LINES) {

            last = 0; /* ptrs to buffer wrap around */
        }

        p += len + 1;
        nlines++;
    }

    if (n > nlines) { /* req. lines more than rec.? */
        
        n = nlines;
    }

    first = last - n;
    
    if (first < 0) {
        
        first += LINES;
    }   

    printf("\n====printing last %d lines====\n", n);

    for (i = first; n-- > 0; i = (i + 1) % LINES) {

        printf("%s", lineptr[i]);
    }

    return 0; // return SUCCESS
}

void _error(char *s)
{
    printf("%s\n", s);
    exit(1);
}

/* _getline: read a line into s, return length */
int _getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }

    if (c == '\n') 
    {
        s[i] = c;
        i++;
    }

    s[i] = '\0';

    return i;
}
