#include <stdio.h>
#include <stdlib.h>
#define MAX 100
// This is from the answer book
void itoa(int, char []);

int main() {
    int n = -157;
    char str[MAX];
    itoa(n, str);
    printf("Int %d to string %s\n", n, str);
    return 0;
}

void itoa(int n, char s[]) {
    static int i;
    if (n / 10) {
        itoa(n / 10, s);
    } else {
        i = 0;
        if (n < 0) {
            s[i++] = '-';
        }
    }
    s[i++] = abs(n) % 10 + '0';
    // Iteratively push ahead '\0' till the real end.
    s[i] = '\0';
}
