#include <stdio.h>
#include <string.h>
// maximum input line length
#define MAXLINE 1000
int myGetline (char line[], int max);
int strrindex(char source[], char searchfor[]);
// pattern to search for
char pattern[] = "ould";
// find all lines matching pattern

int main() {
    char line[MAXLINE];
    while (myGetline(line, MAXLINE) > 0) {
        int found;
        if ((found = strrindex (line, pattern)) >= 0) {
            printf("Rightmost of pattern [%s] is %d\n", pattern, found);
        } else {
            printf("Couldn't find the pattern [%s]\n", pattern);
        }
    }
    return 0;
}
/* myGetline: get line int s, return length */
int myGetline(char s[], int lim) {
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
/* strindex: return the rightmost index of t in s, -1 if none */
int strrindex(char s[], char t[]) {
    int i, j, k;
    int tLen = strlen(t);
    int sLen = strlen(s);
    if (sLen < tLen) {
        return -1;
    }
    for (i = sLen - tLen; i >= 0; i--) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
            ;
        }
        // k > 0 will ensure that t is not a empty string.
        if (k > 0 && t[k] == '\0') {
            return i;
        }
    }
    return -1;
}
