#include <stdio.h>

// echo command-line arguments; 2nd version
int main (int argc, char *argv[]) {
    // use prefix -- because we don't want to count the program itself
    while (--argc > 0) {
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    }
    printf("\n");
    return 0;
}