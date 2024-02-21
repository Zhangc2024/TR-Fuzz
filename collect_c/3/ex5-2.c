/**
 * Exercise 5-2. Write getfloat, the floating-point analog of getint. What type does
 * getfloat return as its function value
 */

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getfloat(float *);

#define SIZE 10

int main()
{
    int n;
    float array[SIZE];

    for(n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        ;

    for(n = 0; n < SIZE && array[n]; n++)
    {
        printf("The value of array %d is %f\n", n, array[n]);
    }

    return 0;// return SUCCESS
}

/* getfloat: get next floating-point number from input */
int getfloat(float *pn)
{
    int c, sign;
    float power;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();

    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0'); /* integer part */

    if (c == '.')
        c = getch();

    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0'); /* fractional part */
        power *= 10.0;
    }

    *pn *= sign / power;
    
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
