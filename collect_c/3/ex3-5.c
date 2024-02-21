#include <stdio.h>
#include <string.h>

/* Exercise 3-5. Write a function itob(n,s,b) that converts the integer n into a base b
 * character representation in the string s. In particular, itob(n,s,16) formats n as
 * a hexadecimal integer in s.
 */

#define abs(x) ((x) > 0 ? (x) : -(x))

void itob(int n, char s[], int b);
void reverse(char s[]);


int main()
{
    char s[50];

    itob(1204, s, 16);

    printf("The hex of decimal 1024 is %s\n", s);

    itob(1204, s, 10);

    printf("The decimal of 1204 is %s\n", s);

    itob(1204, s, 2);

    printf("The binary of 1204 is %s\n", s);

    return 0;// return SUCCESS
}

void itob(int n, char s[], int b)
{
    int i, j, sign;
    
    i = sign = 0;

    if (n < 0)
    {
        sign = 1;
    }

    do {
        
        j = abs(n % b);

        s[i++] = (j <= 9) ? j + '0' :  j - 10 + 'a'; 

    } while ((n /= b) != 0);

    if (sign)
    {
        s[i++] = '-';
    }

    s[i] = '\0';

    reverse(s);
}

void reverse(char s[])
{
    int i, j, s_len;
    char c;

    s_len = strlen(s);
    
    for (i = 0, j = s_len - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
