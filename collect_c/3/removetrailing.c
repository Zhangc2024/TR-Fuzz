#include <stdio.h>
#define MAXLINE 1000        /* maximum length of line input */

int getLine(char line[], int maxline);

main()
{
    int len;                /* length of current input line */
    char line[MAXLINE];     /* current input line */

    while ((len = getLine(line, MAXLINE)) > 0)
        printf("%s", line);

    return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n' && c!='\t'; ++i)
        s[i] = c;
    s[i] = '\0';

    return i;
}
