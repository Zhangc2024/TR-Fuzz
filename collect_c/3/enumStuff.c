# include <stdio.h>

int main() {
    enum months { JAN = 1, FEB, MAR, APR, MAY, JUN,
                  JUL, AUG, SEP, OCT, NOV, DEC };
    for (int m = JAN; m <= DEC; m++) {
        printf("Month: %d\n", m);
    }
    // TODO: not understand why it prints 7 Escape, while there're
    // only 6 elements in enum escapes.
    enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t',
                   NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };
    for (int e = BELL; e <= RETURN; e++) {
        printf("Escape: %c\n", e);
    }
}
