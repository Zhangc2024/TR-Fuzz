#include <float.h>
#include <limits.h>
#include <stdio.h>

/*
Exercise 2-1. Write a program to determine the ranges of char, short,
int, and long variables, both signed and unsigned, by
printing appropriate values from standard headers and by direct computation.
Harder if you com- pute them: determine the ranges of the various floating-point
types.
*/

int main() {

    printf("\n");
    printf("minimums:\n");
    printf("char:  %d\n", CHAR_MIN);
    printf("int:   %d\n", INT_MIN);
    printf("short: %d\n", SHRT_MIN);
    printf("long:  %ld\n", LONG_MIN);
    printf("float: %f\n", FLT_MIN);
    printf("\n");

    printf("signed maximums:\n");
    printf("char:  %d\n", SCHAR_MAX);
    printf("int:   %d\n", INT_MAX);
    printf("short: %d\n", SHRT_MAX);
    printf("long:  %ld\n", LONG_MAX);
    printf("float: %f\n", FLT_MAX);
    printf("\n");

    printf("unsigned number maximums:\n");
    printf("char:  %d\n", UCHAR_MAX);
    printf("int:   %d\n", UINT_MAX);
    printf("long:  %ld\n", ULONG_MAX);

    enum escapes {
        BELL = '\a',
        BACKSPACE = '\b',
        TAB = '\t',
        NEWLINE = '\n',
        VTAB = '\v',
        RETURN = '\r'
    };

    enum escapes escaped;
    escaped = BELL;
}

