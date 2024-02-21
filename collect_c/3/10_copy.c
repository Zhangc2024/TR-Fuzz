#include <stdio.h>

int main() {
    int c;
    c = getchar();

    while(c != EOF) {
        if (c == '\t') printf("\\t");
        else if (c == '\b') printf("\\b");
        else if (c == '\\') printf("\\\\");
        else putchar(c);

        c = getchar();
    }
}