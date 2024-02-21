#include <stdio.h>

int main() {
    int c, isSpace = 0;
    c = getchar();

    while(c != EOF) {
        if (c == ' ') {
            isSpace = 1;
        } else {
            if (isSpace) {
                putchar(' ');
                isSpace = 0;
            }
            putchar(c);
        }
        c = getchar();
    }
}