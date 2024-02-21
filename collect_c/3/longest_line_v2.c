#include <stdio.h>
#include <math.h>
#define MAXLINE 10 /* max input line size */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
void pretty_print(char s[], int len, int lim);
int num_digits(int n);

/* print longest input bline */
int main()
{
    int len;                    /* current line length */
    int max;                    /* maximum lenght seen so far */
    char line[MAXLINE];         /* current input line */
    char longest[MAXLINE];      /* longest line saved here */

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max){
            max = len;
            copy(line, longest);
        }
    if (max > 0)                /* there was a line */
        printf("\n\nlength of longest line:\n%d\n\nlongest line(truncated to %d digits):\n%s\n\n",
               max,
               MAXLINE,
               longest);
    return 0;
}

/**
 * get_line: 
 *  read the first N characters of a line into s (where N = MAXLINE)
 *  return length of line (which may be longer than N and, thus s)
 **/
int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < lim)
            s[i] = c;
    if (c == '\n'){
        if (i < lim)
            s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy `from` into `to`; assume it's big enough */
void copy(char from[], char to[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
