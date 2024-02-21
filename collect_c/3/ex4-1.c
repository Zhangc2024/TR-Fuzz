#include <stdio.h>
#include <string.h>

/* 
 * Exercise 4-1. strrindex(s,t) - returns the position of the rightmost occurence
 * of t in s, or -1 if there is none
 *
 */

#define MAXLINE 1000 /* maximum input line length */

int _getline(char line[], int max);
int strrindex(char source[], char searchfor[]);
void reverse(char s[]);

char pattern[] = "ould"; /* pattern to search */

/* find all lines matching pattern */
int main()
{
    char line[MAXLINE];
    int found = 0;
    int pos   = 0;

    while (_getline(line, MAXLINE) > 0)
    {
        pos = strrindex(line, pattern);

        if (pos >= 0)
        {
            printf("Line\n %s contains %s\n at rightmost index %d\n", line, pattern, pos);
            found++;
        }
    }

    return found;
}

/* getline: get line into s, return length */
int _getline(char s[], int lim)
{
    int c, i;

    i = 0;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }

    if (c == '\n')
    {
        s[i++] = c;
    }

    s[i] = '\0';

    return i;
}

/* strindex: return index of t in s, -1 if none */
int strrindex(char s[], char t[])
{
    int i, j, k;

    /* reverse both the s and t to effectively search from back */
    reverse(s);
    reverse(t);

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
        ;
        
        if (k > 0 && t[k] == '\0')
        {
            /* reverse again to original */
            reverse(s); 
            reverse(t);

            return strlen(s) - k - 1;
        }
    }
    
    reverse(s); 
    reverse(t);

    return -1;
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c    = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
