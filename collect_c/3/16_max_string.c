#include <stdio.h>
#define MAXLINE 1000

int getstring(char line[], int lim);
void copy(char dst[], char src[]);

int main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = getstring(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("Longest line (%d):\n%s", max, longest);
    }

    return 0;
}

int getstring(char s[], int lim) {
    int c, i;

    for (i=0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1) {
            s[i] = c;
        }
    }

    if (i < lim - 1 && c == '\n') {
        s[i++] = c;
    }

    int last;
    last = i;
    if (last > lim - 1) {
        last = lim - 1;
    }

    s[last] = '\0';
    return i;
}

void copy(char dst[], char src[]) {
    int i;

    i=0;
    while ((dst[i] = src[i]) != '\0') {
        ++i;
    }
}