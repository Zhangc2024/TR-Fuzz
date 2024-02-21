/* Write a recursive version of the function reverse(s), which reverses
 * the string s in place
 */

#include <string.h>
#include <stdio.h>

void reverser(char s[], int i, int len);

/* reverse: reverse string s in place */
void reverse(char s[])
{
    reverser(s, 0, strlen(s));
}

/* reverser: reverse string s in place; recursive */
void reverser(char s[], int i, int len)
{
    int c, j;

    j = len - (i + 1);
    if (i < j)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        reverser(s, ++i, len);
    }
}

int main()
{
    char s[] = "Arun";

    reverse(s);

    printf("The reverse of Arun is %s\n", s);

    return 0;//return SUCCESS
}
