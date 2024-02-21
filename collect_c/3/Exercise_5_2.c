#include <ctype.h>
#include <stdio.h>
#define BUFSIZE 100

int getch(void);
void ungetch(int);

// The return type is still int, since the result is ASCII value after
// the float number. The float number is shared by *pn
int getfloat(float *pn) {
    int c, sign, getSign;
    float power;
    /* skip white space */
    while (isspace(c = getch())) {
        ;
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        getSign = c;
        if (!isdigit(c = getch())) {
            if (c != EOF) {
                ungetch(c);
            }
            ungetch(getSign);
            return getSign;
        }
    }
    for (*pn = 0.0; isdigit(c); c = getch()) {
        *pn = 10.0 * (*pn) + (c - '0');
    }
    if (c == '.') {
        c = getch();
    }
    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = 10.0 * (*pn) + (c - '0');
        power *= 10;
    }
    *pn *= sign / power;
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}

char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

/* get a (possibly pushed back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

int main() {
    float n = -10000000.0;
    getfloat(&n);
    if (n == -10000000.0) {
        printf("Input number is invalid.\n");
    } else {
        printf ("The intput number is: %f\n", n);
    }
}