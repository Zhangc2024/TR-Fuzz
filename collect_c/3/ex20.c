#include <stdio.h>

/* Exercise 1-19. Program to reverse  a string */

#define MAXLINE 1000 /* maximum input line size */

int storeLine(char s[], int lim);
void reverseLine(char src[], char dest[], int len);

int main()
{
    int len, new_len; // current line length
    char line[MAXLINE]; // current input line
    char reverse_line[MAXLINE]; // reverse the input line

    while ((len = storeLine(line, MAXLINE)) > 0)
    {   
        printf("Original string is : %s", line);

         reverseLine(line, reverse_line, len);

        printf("New string is : %s", reverse_line);
    }

    return 0; //return SUCCESS
}

void reverseLine(char src[], char dest[], int len)
{
    int i, index;

    index = 0;

    for (i = len - 1; i >= 0; i--)
    {
        dest[index] = src[i];
        index++;
    }
    
    dest[index] = '\0';
}

/* store the line in s and return length */
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

