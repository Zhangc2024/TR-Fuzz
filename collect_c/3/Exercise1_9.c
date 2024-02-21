#include <stdio.h>

int main(){
    int c, lastc;
    lastc = EOF;
    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
        } else if (lastc != ' ') {
            putchar(c);
        }
        lastc = c;
    }
}