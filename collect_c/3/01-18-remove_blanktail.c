#include <stdio.h>
#define MAXLINE 1000        /* maximum input line size */

int getline(char line[], int maxline);
int removetb(char s[]);

/* remove trailing blanks and tabs, and delete blank lines;  */
main()
{
    char line[MAXLINE];     /* current input line */

    while (getline(line,MAXLINE) > 0)
        if (removetb(line) > 0)
            printf("%s", line);
    return 0;
}

/* remove trailing blanks and tabs from character string s */

int removetb(char s[])
{
    int i;

    i = 0;

    while(s[i] != '\n')     /* find newline character */
        ++i;
    --i;                    /* back off from '\n' */
    while(i >= 0 && (s[i] == ' ' || s[i] == '\t'))
        --i;
    if (i >= 0){            /* is it a non blank line ? */
        ++i;
        s[i] = '\n';        /* put newline character back */
        ++i;
        s[i] = '\0';        /* terminate the string */
    }
    return i;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i, j;

    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < lim -2){        /* line still in boundaries */
            s[j] = c;
            ++j;
        }
    if (c == '\n'){
        s[j] = c;
        ++j;
        ++i;
    }
    s[j] = '\0';
    return i;
}
