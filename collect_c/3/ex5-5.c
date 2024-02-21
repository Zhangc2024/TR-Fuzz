/**
 * Exercise 5-5. Write versions of the library functions strncpy, strncat, and
 * strncmp, which operate on at most the first n characters of their argument
 * string. For example, strncpy(s,t,n) copies at most n characters of t to s.
 *
 *
 * based on C Answer book
 *
 */

#include <stdio.h>
#include <string.h>

void _strncpy(char *s, char *t, int n);
void _strncat(char *s, char *t, int n);
int  _strncmp(char *s, char *t, int n);

int main() 
{
    char s[10] = "Hi";
    char t[10] = "There";

    _strncpy(s, t, 5);

    printf("s is now %s\n", s); 

    _strncat(s, t, 5);
    
    printf("s is now %s\n", s);

    printf("compare s and t is %d\n", _strncmp(s, t, 5));

    return 0; // return SUCCESS
}

/**
 * copy n characters from t to s
 *
 *
 */
void _strncpy(char *s, char *t, int n)
{
    while (*t && n-- > 0)
        *s++ = *t++;
    
    while (n-- > 0)
        *s++ = '\0';
}

/**
 * concatenate n characters of t to the end of s
 *
 *
 */
void _strncat(char *s, char *t, int n)
{
    _strncpy(s + strlen(s), t, n);
}

/**
 * compare at most n characters of t with s
 *
 */
int _strncmp(char *s, char *t, int n)
{
    for ( ; *s == *t; s++, t++)
        if (*s == '\0' || --n <= 0)
            return 0;

    return *s - *t;
}
