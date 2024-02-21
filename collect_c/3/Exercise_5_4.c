#include <stdio.h>
#define MAXSIZE 100

int strend(char *s, char *t) {
    // Keep a copy of heads of both strings
    char *bs = s;
    char *bt = t;
    // Loop till the tail of the two strings
    while (*s) {
        s++;
    }
    while (*t) {
        t++;
    }
    // The loop starts from end '\0', so there should be 
    // a check later that it's not stuck at the end
    for (; *s == *t; s--, t--) {
        // Check on boundary
        if (s == bs || t == bt) {
            break;
        }
    }
    // The final check on *s not pointing to '\0' is to 
    // make sure the check really started, since both
    // both tail of s and t will point to terminator '\0'
    if (t == bt && *s == *t && *t != '\0') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char *s = "Hello darkness my old friend";
    char *t1 = "friend";
    char *t2 = "old";
    printf("[%s]%s occur(s) at the end of [%s]\n", t1, strend(s, t1) == 1? "":" doesn't", s);
    printf("[%s]%s occur(s) at the end of [%s]\n", t2, strend(s, t2) == 1? "":" doesn't", s);
}