#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXLEN 100      /* maximum length of string */

void itoa(int n, char s[]);
void reverse(char s[]);

main()
{
    char s[MAXLEN];
    int n = INT_MIN;
    itoa(n, s);

    printf("%d = %s\n", n, s);

    return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign, exceedMin = 0;

    if ((sign = n) < 0) {   /* record sign */
        if (n > INT_MIN)
            n = -n;             /* make n positive */
        else {
            n = INT_MAX;
            exceedMin = 1;
        }
    }
    i = 0;
    do {        /* generate digits in reverse order */
       s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);    /* delete it */
    if (sign < 0)
    {
        if (exceedMin)
            s[0] += 1;
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
