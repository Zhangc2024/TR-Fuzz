#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */
#define MINLINE 80      /* minimum ouput line size */

int getLine(char line[], int lim);

/* print all input lines longer than 80 characters */
main()
{
    int len;            /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = getLine(line, MAXLINE)) > 0)
        if (len > MINLINE)
            printf("%s", line);
    return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;
    
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
