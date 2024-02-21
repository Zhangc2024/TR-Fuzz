#include <stdio.h>

void print_name() {
    int i;
    char s[2];
    extern char name[];

    for(i=0; i < sizeof(name); i++) {
        s[0] = name[i];
        s[1] = '\0';
        printf("%s", s);
    }

    printf("\n");
}
