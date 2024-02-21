#include <stdio.h>
#include <string.h>

#define MAXLEN 100      /* maximum length of string */

void itoa(int n, char s[], int minWidth);
void reverse(char s[]);

main()
{
    char s[MAXLEN];
    int n = -1959751051, minWidth = 15;
    itoa(n, s, minWidth);

    printf("%d = %s\n", n, s);

    return 0;
}

/* itoa: convert n to characters in s padded with zeros
 * if shorter than minWidth */
void itoa(int n, char s[], int minWidth)
{
    int i, sign;

    if ((sign = n) < 0) /* record sign */
        n = -n;         /* make n positive */
    i = 0;
    do {        /* generate digits in reverse order */
       s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    while (i < minWidth - 1) /* pad with zeros */
        s[i++] = ' ';
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
