/* Adapt the ideas of 'printd' to write a recursive version of itoa; that is, convert
 * an integer into a string by calling a recursive routine
 */

#include <stdlib.h> //for abs()
#include <stdio.h>

/* itoa: convert n to characters in s; recursive */

void itoa(int n, char s[])
{
    static int i;

    if (n / 10)
        itoa(n / 10, s);
    else {
        i = 0;
        if (n < 0)
            s[i++] = '-';
    }

    s[i++] = abs(n) % 10 + '0';
    s[i]   = '\0';
}

int main()
{
    char s[10];
    itoa(123, s);
    printf("itoa of 123 is %s\n",s);

    return 0;//return SUCCESS
}
