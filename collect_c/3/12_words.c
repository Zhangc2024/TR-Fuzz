#include <stdio.h>

#define WORD 1
#define BREAK 0

int main() {
    int c, state;
    state = BREAK;

    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == WORD) {
                putchar('\n');
                state = BREAK;
            }
            continue;
        }

        putchar(c);
        state = WORD;
    }
}