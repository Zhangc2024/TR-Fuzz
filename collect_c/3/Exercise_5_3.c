#include <stdio.h>
#define MAXSIZE 100

void mystrcat(char *s, char *t) {
    while (*s) {
        s++;
    }
    while (*(s++) = *(t++)) {
        ;
    }
}

int main () {
    char s[MAXSIZE] = "Sound of silence; ";
    char t[MAXSIZE] = "hello darkness, my old friend.";
    printf("s: [%s], t: [%s]\n", s, t);
    mystrcat(s, t);
    printf("After strcat: [%s]\n", s);
}