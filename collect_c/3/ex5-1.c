#include <stdio.h>
#include <ctype.h>

/**
 * As written, getint treats a + or - not followed by a digit as a valid representation
 * of zero. Fix it to push such a character back on the input. Based on C answer book.
 */

int getch(void);
void ungetch(int);
int getint(int *);

#define SIZE 10

int main()
{
    int n, array[SIZE];

    for(n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;

    for(n = 0; n < SIZE && array[n]; n++)
    {
        printf("The value of array %d is %d\n", n, array[n]);
    }

    return 0;// return SUCCESS
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, d, sign;

    while(isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    
    if (c == '+' || c == '-') {
        d = c;
        if (!isdigit(c = getch())) {
            if (c != EOF)
                ungetch(c);
            ungetch(d);
            return d;
        }
    }

    for (*pn = 0; isdigit(c); c = getch())
         *pn = 10 * *pn + (c - '0'); 
    *pn *= sign;
    if (c != EOF)
        ungetch(c);

    return c;
}

char buf = 0; /* buffer for ungetch */

int getch(void) /* get a (possibly pushed back) character */
{
    int c;

    if (buf != 0) {
        c = buf;
    } else {
        c = getchar();
    }

    buf = 0;

    return c;
}

/* push character back on input */
void ungetch(int c) 
{
    if (buf != 0) {
        printf("ungetch: too many characters\n");
    } else {
        buf = c;
    }
}
