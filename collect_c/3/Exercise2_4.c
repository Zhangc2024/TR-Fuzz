#include <stdio.h>
#include<stdbool.h>

void squeeze_v1(char s1[], char s2[]);
void squeeze_v2(char s1[], char s2[]);

int main() {
    char s1[] = "Hello, world!";
    char s2[] = "woe!";
    printf("s1: %s, s2: %s\n", s1, s2);
    squeeze_v2(s1, s2);
    printf("After squeezing, s1: %s\n", s1);
}

/* squeeze: delete each char in s1 which is in s2 */
void squeeze_v1(char s1[], char s2[]) {
    int k = 0;
    bool same;
    for (int i = 0; s1[i] != '\0'; i++) {
        same = false;
        for (int j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                same = true;
            }
        }
        if (!same) {
            s1[k++] = s1[i];
        }
    }
    s1[k] = '\0';
}

void squeeze_v2(char s1[], char s2[]) {
    int k = 0;
    int i, j;
    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0' && s1[i] != s2[j]; j++) {
            ;
        }
        if (s2[j] == '\0') {
            s1[k++] = s1[i];
        }
    }
    s1[k] = '\0';
}
