/** 
 * 
 * Ex5-4. Write a function strend(s, t), which returns 1 if the string
 * t occurs at the end of the string s, and zero otherwise 
 *
 * based on C answer book
 *
 */

#include <stdio.h>

int strend(char *, char *);

int main () {

    char *s = "Arun";
    char *t = "un";

    int is_t_at_end_of_s = strend(s, t);
    
    printf("Is string '%s' occurs at end of '%s' ? %s\n",
            t, s, is_t_at_end_of_s == 1 ? "Yes" : "No");


    return 0; //return SUCCESS
}

int strend(char *s, char *t)
{
    char *bs = s;
    char *bt = t;

    for ( ; *s ; s++)
        ;
    for ( ; *t ; t++)
        ;

    for ( ; *s == *t; s--, t--)
        if (t == bt || s == bs)
            break;

    if (*s == *t && t == bt && s != '\0')
        return 1;
    else
        return 0;
}

