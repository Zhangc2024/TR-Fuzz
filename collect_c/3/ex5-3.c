#include <stdio.h>

/* 
 * Exercise 5-3. Write a pointer version of the function strcat that we showed
 * in Chapter2: strcat(s, t) copies the string t to the end s.
 */

void _strcat(char *s1, char *s2);

int main()
{
    char source[20] = "Hi There!";
    char dest[20]   = "DrCatcher";

    _strcat(source, dest);

    printf("The result is %s\n", source);

    return 0; //return SUCCESS
}

void _strcat(char *s1, char *s2) {
    
    while(*s1)
        s1++;

    while((*s1++ = *s2++))
        ;
}
