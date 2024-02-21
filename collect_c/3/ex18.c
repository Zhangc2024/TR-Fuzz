#include <stdio.h>

/* 1.9 Arrays: print line > MAX_CHARS */

#define MAXLINE 1000 /* maximum input line size */
#define MAX_CHARS 80 /* maximum input line characters */

int getlineLength(char line[], int maxline);

int main()
{
    int len; // current line length
    char line[MAXLINE]; // current input line

    while ((len = getlineLength(line, MAXLINE)) > 0)
    {
        if (len > MAX_CHARS)
        {
            printf("The input line longer than %d is : %s\n", MAX_CHARS, line);   
        }
    }

    return 0; //return SUCCESS
}

/* getlineLength: read a line and return it's length */
int getlineLength(char s[], int lim)
{
    int c, i;

    i = 0;

    while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
    {
        s[i] = c;
        i++;
    }
        
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }

    s[i] = '\0';

    return i;
}
