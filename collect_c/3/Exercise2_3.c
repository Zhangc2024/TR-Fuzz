#include<stdio.h>
/* htoi: convert hex to int */
int myhtoi(char s[]);

int main () {
    char s[] = "0x22";
    printf("Hex s: %s to int: %d\n", s, myhtoi(s));
    return 1;
}

int myhtoi(char s[]) {
    // We accept "0x" or "0X"
    if (s[0] != '0' || ((s[1] != 'x') && (s[1] != 'X'))) {
        return -1;
    }
    int n = 0;
    for (int i = 2; s[i] != '\0'; i++) {
        int curr;
        if (s[i] >= '0' && s[i] <= '9') {
            curr = s[i] - '0';
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            curr = s[i] - 'a' + 10;
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            curr = s[i] = 'A' + 10;
        } else {
            return -1;
        }
        n = 16 * n + curr;
    }
    return n;
}