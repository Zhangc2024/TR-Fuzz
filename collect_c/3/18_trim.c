#include <stdio.h>
#define BUFLEN 1000

int main() {
    char cur;
    char buf[BUFLEN];
    int bi, i, br;
    bi = i = br = 0;

    while ((cur = getchar()) != EOF) {
        if (cur == ' ' || cur == '\t') {
            if (bi < BUFLEN) {
                buf[bi++] = cur;
            }

            continue;
        }

        if (bi > 0 && cur != '\n') {
            if (br) {
                putchar('\n');
                br = 0;
            }

            for (i = 0; i < bi; ++i) {
                putchar(buf[i]);
            }
        }

        if (cur == '\n') {
            br = 1;
            bi = 0;
            continue;
        }

        if (br) {
            putchar('\n');
            br = 0;
        }

        bi = 0;
        putchar(cur);
    }

    return 0;
}