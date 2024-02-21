#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strrindex(char source[], char searchfor[]);
char pattern[] = "ould";

/* find all lines matching pattern */
main()
{
    char line[MAXLINE];
    int found = 0;
    int pos;

    while (getline(line, MAXLINE) > 0)
    if ((pos = strrindex(line, pattern)) >= 0){
        printf("%s %d \n", line, pos);
        found++;
    }
    return found;
}

/* strrindex: returns rightmost index of i in s, -1 if none*/
int strrindex(char s[], char t[])
{
    int i, j, k, pos;

    pos = -1;
    for (i = 0; s[i] != '\0'; i++){
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            pos = i;
    }
    return pos;
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
