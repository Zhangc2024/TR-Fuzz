/*
 * sort4:  Sorts input lines supporting reverse and numeric ordering using '-r', '-n', '-f', and '-d' switches
 *         plus being able to sort on a field range defined by '-pos' to '+pos'.
 */

// The following definition change is needed to allow the use of getline() in this
// example without having to call it something else.
// c.f. http://stackoverflow.com/questions/37474117/how-to-implement-custom-versions-of-the-getline-function-in-stdio-h-clang-os-x

/*@ -statictrans  -mustfreefresh  -nullret -compdef */

#undef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L

// Includes

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definitions

#define ALLOCSIZE 10000000  // Maximum available storage (simulated)
#define MAXLEN        1000  // Maximum length of any input line
#define MAXLINES     10000  // Maximum number of lines to be sorted

// Globals

static char   allocbuf[ALLOCSIZE]; // Storage for alloc
static char  *allocp = allocbuf;   // Next free position in alloc
static char  *lineptr[MAXLINES];   // Pointers to text lines
static size_t pos1;                // Starting position of sort field
static size_t pos2;                // Ending position of sort field
static bool   numeric = false;     // 'true' if numeric sort
static bool   descend = false;     // 'true' if descending output
static bool   fold    = false;     // 'true' if case insensitive sort
static bool   dir     = false;     // 'true' if directory order sort

/*
 * alloc(): rudimentary storage allocator
 */

static char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) { // it fits
        allocp += n;
        return allocp - n; // old p
    }
    return 0; // not enough room
}

/* getline: read an aribitrarily long line placing as much as
 * possible into 's' and returning the full length
 */

static size_t getline(char *s, size_t lim) {

    char c;
    char *sindex = s;

    while (--lim > 0 && (c = (char)getchar()) != (char)EOF && c != '\n')
        *sindex++ = c;
    if (c == '\n')
        *sindex++ = c;
    *sindex = '\0';

    return (size_t)(sindex - s);
}


/*
 * readlines(): read input lines
 */

static int readlines(char *lineptr[], int maxlines) {

    size_t len;
    int    nlines;
    char  *p;
    char   line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0) {

        if ((p = alloc((int)len)) == NULL || nlines >= maxlines)
            return -1;

        line[len - 1] = '\0';
        strcpy(p, line);
        lineptr[nlines++] = p;

    }

    return nlines;
}

/*
 * writelines(): outputs each string in the passed array of strings
 */

static void writelines(char *lineptr[], int nlines, bool descend) {
    int i;
    if (descend)
        for (i = nlines - 1; i > -1; i--)
            printf("%s\n", lineptr[i]);
    else
        for (i = 0; i < nlines; i++)
            printf("%s\n", lineptr[i]);
}

/*
 * error(): print error messages
 */

static void error(char *s) {
    printf("%s\n", s);
    exit(EXIT_FAILURE);
}

/*
 * substr(): get a substring of s and put it into str
 */

static void substr(const char *s, char *str) {

    size_t i;
    size_t j;
    size_t len;

    len = strlen(s);

    if (pos2 != 0 && pos2 < len)
        len = pos2;
    else if (pos2 != 0 && len < pos2)
        error("substr: string is too short");

    for (j = 0, i = pos1; i < len; i++, j++)
        str[j] = str[i];

    str[j] = '\0';

}

/*
 * swap(): interchanges v[i] and v[j]
 */

static void swap(void *v[], int i, int j) {
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/*
 * numcmp(): compares two numbers
 */

static int numcmp(const char *s1, const char *s2) {

    double v1;
    double v2;
    char   str[1000];

    substr(s1, str);
    v1 = atof(s1);

    substr(s2, str);
    v2 = atof(s2);


    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

/*
 * foldcmp(): compares strings ignoring case in the process
 */

static int foldcmp(const char *s, const char *t) {

    size_t  i = pos1;
    size_t  j = pos1;
    size_t  endpos;

    if (pos2 > 0)
        endpos = pos2;
    else if ((endpos = strlen(s)) > strlen(t))
        endpos = strlen(t);

    for ( ; tolower(s[i]) == tolower(t[j]) && i < endpos && j < endpos; i++, j++)
        if (s[i] == '\0')
            return 0;

    return tolower(s[i]) - tolower(t[j]);
}

/*
 * dircmp(): compares strings in directory order
 */

static int dircmp(const char *s, const char *t) {

    char   a;
    char   b;
    size_t i = pos1;
    size_t j = pos1;
    size_t endpos;

    if (pos2 > 0)
        endpos = pos2;
    else if ((endpos = strlen(s)) > strlen(t))
        endpos = strlen(t);

    do {

        while (i < endpos && !isalnum(s[i]) && s[i] != ' ' && s[i] != '\0')
            i++;
        while (j < endpos && !isalnum(t[j]) && t[j] != ' ' && t[j] != '\0')
            j++;

        a = s[i++];
        b = t[j++];

        if (a == '\0' && b == '\0')
            return 0;

    } while (a == b && i < endpos && j < endpos);

    return a - b;

}

/*
 * folddircmp(): compares strings in directory order
 */

static int folddircmp(const char *s, const char *t) {

    char a;
    char b;
    size_t i = pos1;
    size_t j = pos1;
    size_t endpos;

    if (pos2 > 0)
        endpos = pos2;
    else if ((endpos = strlen(s)) > strlen(t))
        endpos = strlen(t);

    do {

        while (i < endpos && !isalnum(s[i]) && s[i] != ' ' && s[i] != '\0')
            i++;
        while (j < endpos && !isalnum(t[j]) && t[j] != ' ' && t[j] != '\0')
            j++;

        a = tolower(s[i++]);
        b = tolower(t[j++]);

        if (a == '\0' && b == '\0')
            return 0;

    } while (a == b && i < endpos && j < endpos);

    return a - b;

}

/*
 * qsort(): sort v[left]...v[right] into increasing order
 */

static void myqsort(void *v[], int left, int right, int (*comp)(void *, void *)) {

    int i;
    int last;

    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    myqsort(v, left, last - 1,  comp);
    myqsort(v, last + 1, right, comp);

}

/*
 * readargs(): read arguments
 */

static void readargs(int argc, char *argv[]) {

    int c;

    while (--argc > 0 && ((c = (*++argv)[0]) == '-' || c == '+'))
        if (c == '-' && !isdigit(*(argv[0]+1)))
            while ((c = *++argv[0]) != '\0')
                switch (c) {
                    case 'n':
                        numeric = true;
                        break;
                    case 'r':
                        descend = true;
                        break;
                    case 'f':
                        fold = true;
                        break;
                    case 'd':
                        dir = true;
                        break;
                    default:
                        printf("sort: illegal option %c\n", c);
                        exit(EXIT_FAILURE);
                }
        else if (c == '-')
            pos2 = (size_t)atoi(argv[0]+1);
        else
            pos1 = (size_t)atoi(argv[0]+1);

    if ((argc == 0) || (pos1 > pos2))
        error("usage: sort -dnfr [+pos1] [-pos2] [FILE]");

}

/*
 * Main
 */

int main(int argc, char *argv[]) {

    int  nlines;          // Number of input lines to read

    // Evaluate arguments

    readargs(argc, argv);

    // Read in the lines into memory

    if ((nlines = readlines(lineptr, MAXLINES)) < 0) {
        printf("Input is too big to sort\n");
        exit(EXIT_FAILURE);
    }

    // Sort

    if (numeric)
        myqsort(
                (void **) lineptr,
                0,
                nlines - 1,
                (int (*)(void*, void*))numcmp
            );
    else if (fold && dir)
        myqsort(
                (void **) lineptr,
                0,
                nlines - 1,
                (int (*)(void*, void*))folddircmp
            );
    else if (fold)
        myqsort(
                (void **) lineptr,
                0,
                nlines - 1,
                (int (*)(void*, void*))foldcmp
            );
    else if (dir)
        myqsort(
                (void **) lineptr,
                0,
                nlines - 1,
                (int (*)(void*, void*))dircmp
            );
    else
        myqsort(
                (void **) lineptr,
                0,
                nlines - 1,
                (int (*)(void*, void*))strcmp
            );

    // Write out the results

    writelines(lineptr, nlines, descend);

    return 0;
}
