/*
    Variables

    Variables are simply names for data storage locations.

    You declare variables in the simple form: type variableName;
    You can also initialize at the same time with: type variableName = value;
    See examples below for more info.

    There are a few data types in C. Below are some examples, but a list by C revision number can be found here:
    https://en.wikibooks.org/wiki/C_Programming/Language_Reference

    A list of format specifiers for printf() can be found here: https://en.cppreference.com/w/c/io/fprintf
*/

#include <stdio.h>

int main(void)
{
    unsigned char bacon = 255;  /* variable 'bacon' holds a number from 0 to 255 */
    printf("%u\n", bacon);      /* print bacon (an unsigned char) in decimal representation */

    char firstLetter = 'A';         /* variable 'firstLetter' holds the ascii value (65) for the character A */
    printf("%c\n", firstLetter);    /* but we can print it as a character */

    int potatoes = 5;
    printf("%d\n", potatoes);   /* print potatoes (a signed integer) in decimal representation */

    double cash = 1034.89;
    printf("%g\n", cash);

    return 0;
}

/*
    Extra

    Want to understand more?
    What does variable 'bacon' become if we add this code at line 18? Why?

    value++;
    printf("%u\n", value);
*/