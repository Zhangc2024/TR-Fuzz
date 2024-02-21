#include <stdio.h>

int main() {
    double cs, ct, cb;
    int c;

    c = getchar();
    while (c != EOF) {
        if (c == ' ') ++cs;
        if (c == '\t') ++ct;
        if (c == '\n') ++cb;
        c = getchar();
    }

    printf("Spaces: %.0f, tabs: %.0f, breaks: %.0f", cs, ct, cb);
}