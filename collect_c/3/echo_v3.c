#include <stdio.h>

// echo command-line arguments; 2nd version
int main (int argc, char *argv[]) {
    // use prefix -- because we don't want to count the program itself
    while (--argc > 0) {
        printf((argc > 1) ? "%s " : "%s", *++argv);
    }
    printf("\n");
    return 0;
}