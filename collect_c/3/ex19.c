#include <stdio.h>

/* Exercise 1-18 - A program to remove trailing blanks and tabs from each
 * line of input and to delete entirely blank lines */

#define MAXLINE 1000 /* maximum input line size */

int storeLine(char s[], int lim);
int removeTrail(char s[], int len);

int main()
{
    int len, new_len; // current line length
    char line[MAXLINE]; // current input line

    while ((len = storeLine(line, MAXLINE)) > 0)
    {   
        printf("Length is %d\n", len);

        new_len = removeTrail(line, len);

        printf("New Length is %d\n", new_len);
    }

    return 0; //return SUCCESS
}

int removeTrail(char s[], int len)
{
    char line[MAXLINE];

    int i, index;

    index = 0;

    for (i = 0; i < len; i++)
    {
        if (s[i] != ' ' && s[i] != '\t') {

            line[index] = s[i];
            index++;
        }    
    }
    
    line[index] = '\0';

    return index;
}

/* store the line in s */
int storeLine(char s[], int lim)
{
    int c, i;

    i = 0;

    while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
    {
        s[i] = c;
        i++;
    }
        
    if (i != 0 && c == '\n')
    {
        s[i] = c;
        i++;
    }

    s[i] = '\0';

    return i;
}
