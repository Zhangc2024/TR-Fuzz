#include <stdio.h>

/* Exercise 1-16. Print the length of arbitrary long input lines */

#define MAXLINE 1000 /* maximum input line size */

int _getline(char line[], int maxline);
void _copy(char to[], char from[]);

int main()
{

    int len; // current line length
    int max; // maximum length seen so far

    char line[MAXLINE]; // current input line
    char longest[MAXLINE]; // longest line saved here

    max = 0;

    while ((len = _getline(line, MAXLINE)) > 0)
    {
        
        printf("Current Line Length is : %d\n", len);
        printf("Current Line is : %s\n", line);

        if (len > max)
        {
            max = len;
            _copy(longest, line);
        }
    }

    if (max > 0) /* there was a line */
        printf("\nLongest line so far is : %s\n", longest);

    return 0; //return SUCCESS
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void _copy(char to[], char from[])
{
    int i;
    
    i = 0;

    while ((to[i] = from[i]) != '\0')
        i++;
}
