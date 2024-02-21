#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */
#define MAXLEN 40       /* maximum line length before fold is created */

int getLine(char line[], int maxline);
void foldLine(char line[], int len);

main()
{
    int len;                /* length of current line */
    char line[MAXLINE];     /* current input line */

    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > MAXLEN) foldLine(line, len);
        else printf("%s", line);
    }

    return 0;
}

/* getLine: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;

    for (i=0; i <lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* foldLine: fold the length of the input line into the output line */
void foldLine(char line[], int len)
{
    int i = len-1;

    while (i > MAXLEN) {
        if (line[i] == ' ' || line[i] == '\t') {
            while (line[i-1] == ' ' || line[i-1] == '\t')
                --i;
            line[i] = '\n';
            i = i - MAXLEN;
        }
        else if (i > 0) --i;
        else break;
    }
    printf("%s", line);
}
