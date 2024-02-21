#include <stdio.h>
#define MAXLEN 100

void reverse(char[]);

int main() {
    char buf[MAXLEN], revbuf[MAXLEN];
    char c;
    int i;
    i = 0;

    while((c = getchar()) != EOF && i < MAXLEN) {
        if (c == '\n') {
            buf[i] = '\0';
            reverse(buf);
            printf("%s\n", buf);
            i = 0;
            continue;
        }

        buf[i++] = c;
    }

    return 0;
}

void reverse(char str[]) {
    char buf[MAXLEN];
    int i;
    i = 0;

    while(str[i++] != '\0') {
        buf[i-1] = str[i-1];
    }

    int last = i - 1;
    str[last] = '\0';
    --i;
    --last;
    while(--i >= 0) {
        str[last-i] = buf[i];
    }
}