#include <stdio.h>

/* Copy input to output, replace 1 or more blanks with a single blank */

int main() {

    int c, prev;

    while((c = getchar()) != EOF) {
        if (c != ' ' || prev != ' ') {
            putchar(c);
            prev = c;
        }
    }
}
