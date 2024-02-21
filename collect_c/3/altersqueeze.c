#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int getLine(char line[], int maxline);
void squeeze(char s1[], char s2[]);

main()
{
    int len;        /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = getLine(line, MAXLINE)) > 0) {
        squeeze(line, "aeiouAEIOU");
        printf("%s", line);
    }

    return 0;
}

/* getLine: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

/* squeeze: delete all characters in s2 from s1 */
void squeeze(char s1[], char s2[])
{
    int i, j, k, flag = 0;

    for (i = j = 0; s1[i] != '\0'; i++) {

        for (k = flag = 0; s2[k] != '\0'; k++)
            if (s1[i] == s2[k]) flag = 1;

        if (!flag) s1[j++] = s1[i];
    }
    s1[j] = '\0';
}
