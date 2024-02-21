#include <stdio.h>
#include <string.h>

/*
 *
 * Exercise 3-6.  itoa: convert n to characters in s. It accepts three arguments instead of
 * two. The third argument is a minimum field width. The converted number must be padded with
 * blanks ('x') on the left if necessary to make it wide enough.
 *
 */

void itoa(int n, char s[], int min_len);
void reverse(char s[]);
void padAfter(char s[], int n);

int main()
{
    char s[60];
    
    itoa(1234, s, 10);

    printf ("The string of 1234 is %s\n", s);
    
    itoa(12456, s, 20);

    printf ("The string of 12456 is %s\n", s);

    return 0; //return SUCCESS
}

void itoa(int n, char s[], int min_len)
{
    int i, sign, len;

    if ((sign = n) < 0)
    {
        n = -n;
    }

    i = 0;

    do {

        s[i++] = n % 10 + '0';

    } while ((n /= 10) > 0);

    if (sign < 0)
    {
        s[i++] = '-';
    }

    s[i] = '\0'; 
    
    len = strlen(s);
    
    if (len < min_len)
    {
        padAfter(s, min_len - len); 
    }

    reverse(s);
}

void reverse(char s[])
{
    int s_len = strlen(s);
    int i, j;  
    char c;

    for (i = 0, j = s_len - 1; i < j ; i++, j--)
    {
        c    = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void padAfter(char s[], int n)
{
    int s_len = strlen(s);

    while (n > 0)
    {
        s[s_len++] = 'x'; // lets make it 'x' instead of white char to see it visibly
        n--;
    }

    s[s_len] = '\0';
}
