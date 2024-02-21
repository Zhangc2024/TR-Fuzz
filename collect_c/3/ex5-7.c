/* 
 * Exercise 5-7. Rewrite readlines to store lines in an array supplied by main, rather than
 * calling alloc to maintain storage. How much faster is the program.
 *
 * adapted from C answer book
 */

#include <string.h>

#define MAXLEN 1000 /* maximum length of line */
#define MAXSTOR 5000 /* size of available storage space */

int getline(char *, int);

int main()
{
    
    return 0; //return SUCCESS
}

/* readlines: read input lines */
int readlines(char *lineptr[], char *linestor, int maxlines)
{
    int len, nlines;
    char line[MAXLEN];
    char *p = linestor; //start of the line
    char *linestop = linestor + MAXSTOR; //end of the line
    
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0) {

        if (nlines >= maxlines || p + len > linestop) {
            return -1;
        }
        else {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    
    return nlines;
}




