/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
#include <stdio.h>

int myStrcmp_v1(char *s, char *t) {
    int i;

    for (i = 0; s[i] == t[i]; i++) {
        if (s[i] == '\0') {
            return 0;
        }
    }
    return s[i] - t[i];
}

int myStrcmp_v2(char *s, char *t) {
    for ( ; *s == *t; s++, t++) {
        if (*s == '\0') {
            return 0;
        }
    }
    return *s - *t;
}

int main() {
    char s[] = "program";
    char t[] = "progress";
    int result1 = myStrcmp_v1(s, t);
    int result2 = myStrcmp_v2(s, t);
    if (result1 < 0 && result2 < 0) {
        printf("%s is before %s\n", s, t);
    } else if (result1 == 0 && result2 == 0) {
        printf("%s is lexically equal to %s\n", s, t);
    } else if (result1 > 0 && result2 > 0) {
        printf("%s is after %s\n", s, t);
    }
}