/**
 * Rewrite appropriate programs from earlier chapters and exercises with pointers
 * instead of array indexing. Good possibilities include getline, atoi, itoa, and
 * their variants, reverse, and strindex and getop
 *
 * based on C answer book.
 */

#include <stdio.h>
#include <ctype.h>  //for isspace()
#include <string.h> //for reverse()

int _getline(char *s, int lim);
int atoi(char *s);
void itoa(int n, char *s);
void reverse(char *s);
double atof(char *s);

int main() 
{
    //nothing to see. move on!

    return 0; // return SUCCESS
}

/* getline: read a line into s, return length */
int _getline(char *s, int lim)
{
    int c;
    char *t = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;

    if (c == '\n')
        *s++ = c;

    *s = '\0';

    return s - t; // return the number of characters in s including '\0'
}

/* atoi: convert s to integer; pointer version */
int atoi(char *s)
{
    int n, sign;

    for ( ; isspace(*s); s++) /* skip white space */
        ;

    sign = (*s == '-') ? -1 : +1; 
    
    if (*s == '+' || *s == '-') // skip sign
        s++;

    for (n = 0; isdigit(*s); s++)
        n = 10 * n + *s - '0'; 

    return sign  * n;
}

/* itoa: convert n to characters in s; pointer version */
void itoa(int n, char *s)
{
    int sign;
    char *t = s; //store the first index pointer
    
    if ((sign = n) < 0) //store the number
        n = -n; //reset the sign of the number to positive value

    do {
        *s++ = n % 10 + '0'; //store it as array of characters in reverse order
    } while (( n /= 10) > 0);

    if (sign < 0)
        *s++ = '-';

    *s = '\0';

    reverse(t);
}

/* reverse: reverse string s in place */
void reverse(char *s)
{
    int c;
    char *t;
    
    for (t = s + strlen(s) - 1; s < t; s++, t--) {
        c = *s;
        *s = *t;
        *t = c;
    }
}

/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t)
{
    char *b = s; //beginning of string s
    char *p, *r;

    for(; *s != '\0'; s++) {
        for (p = s, r = t; *r != '\0' && *p == *r; p++, r++)
            ;
        if (r > t && *r == '\0')
            return s - b; // offset distance of t from s
    }

    return -1;
}

/* atof: convert string s to double; pointer version */
double atof(char *s)
{
    double val, power;
    int sign;

    for ( ; isspace(*s); s++) // skip white space
        ;

    sign = (*s == '-') ? -1 : 1;

    if (*s == '+' || *s == '-')
        s++;

    for (val = 0.0; isdigit(*s); s++)
        val = 10.0 * val + (*s - '0');

    if (*s == '.')
        s++;

    for (power = 1.0; isdigit(*s); s++) { // 
        val = 10.0 * val + (*s - '0');
        power *= 10.0;
    }

    return sign * val / power;
}

#define NUMBER '0' // signal that a number was found

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand; pointer ver */
int getop(char *s)
{
    int c;

    while ((*s = c = getch()) == ' ' || c == '\t')
        ;

    *(s + 1) = '\0';

    if (!isdigit(c) && c != '.')
        return c;
    
    if (isdigit(c))
        while (isdigit(*++s = c = getch()))
            ;

    if (c == '.')
        while (isdigit(*++s = c = getch()))
            ;

    *s = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

char buf = 0;

int getch(void)
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

void ungetch(int c)
{
    if (buf != 0) {
        printf("ungetch: too many characters\n");
    } else {
        buf = c;
    }
}
