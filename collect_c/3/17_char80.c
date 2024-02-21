#include <stdio.h>
#define MAXLEN 80

int main() {
    char cur;
    char buf[MAXLEN];
    int bi, i, flush, br;
    bi = flush = br = 0;

    while ((cur = getchar()) != EOF) {
        if (cur == '\n') {
            bi = flush = 0;
            br = 1;
            continue;
        }

        if (bi < MAXLEN) {
            buf[bi++] = cur;
            continue;
        }

        if (flush == 0) {
            if (br) {
                putchar('\n');
                br = 0;
            }
            for (i = 0; i < bi; ++i) {
                putchar(buf[i]);
            }
        }

        flush = 1;
        putchar(cur);
    }

    return 0;
}
