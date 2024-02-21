/*
    Strings

    C doesn't *really* have strings... But there are many things in C (and the STL) to give you
    power over strings. Essentially, when you have a "string", it's a pointer to the first
    character in a contiguous set of char's in memory.

    You can also put a string in a char array, and manipulate items individually.
    (There's a lot more you can do, as it is with every example, but this is just the basics.)

    Format specifier notes...
    %c is for printing a character
    %s is for printing a character array (a "string")
*/

#include <stdio.h>

int main(void)
{
    printf("Hello world!\n");   /* This is a string! It's type is char* (a pointer to a set of characters) */

    char *s = "I like bacon!";  /* Make a string and set the pointer to the first char */

    printf("%c\n", *s);         /* Dereference s, the character pointer. Gets the first item from our character array s */

    printf("%s\n", s);          /* Print the whole string (aka the char array). Notice we passed the pointer. */

    printf("%c\n", s[7]);       /* Access the 7th index from our string... which is also a character array */

    return 0;
}