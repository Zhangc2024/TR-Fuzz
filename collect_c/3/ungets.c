/*
 * Provides a buffered read of characters from standard input allowing characters to be
 * 'pushed back' and then re-read again.
 *
 * The buffer is implemented as a stack
 */

// Includes

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definitions

#define MAXSTR   100
#define MAXSTACK 100 // Maximum depth of buffer (stack)

// Globals

static size_t bufferptr = 0;    // Buffer pointer--next free stack position
static char   buffer[MAXSTACK]; // Array-based buffer of char-typed values

/*
 * getch(): gets a character from the buffer
 */

static char getch(void) {
    return (bufferptr > 0) ? buffer[--bufferptr] : getchar();
}

/*
 * ungetch(): ungets a character from the buffer
 */

static void ungetch(char c) {

    if (bufferptr >= MAXSTACK) {
        printf("ungetch(): buffer overflow\n");
        exit(EXIT_FAILURE);
    }

    buffer[bufferptr++] = c;
}

/*
 * ungets(): ungets a whole string back to the buffer
 */

static void ungets(char s[]) {
    size_t slen = strlen(s);
    while (slen > 0)
        ungetch(s[--slen]);
    s[0] = '\0';
}

/* Main */

int main(void) {

    char   s[MAXSTR]; // test string
    size_t i;         // string index
    char   c;         // last character read

    printf("Reading 10 characters from input...\n");
    i = 0;
    c = getch();
    while ((c = getch()) != EOF && i < 10)
        s[i++] = c;
    s[i] = '\0';
    printf("\t... result: \"%s\"\n", s);

    printf("Pushing back 1 character to input...\n");
    ungetch(s[--i]);
    s[i] = '\0';
    printf("\t... result: \"%s\"\n", s);

    printf("Reading 1 character from input...\n");
    s[i++] = getch();
    s[i] = '\0';
    printf("\t... result: \"%s\"\n", s);

    printf("Pushing back whole string to input...\n");
    ungets(s);
    printf("\t... result: \"%s\"\n", s);

    printf("Reading 10 characters from input...\n");
    i = 0;
    while ((c = getch()) != EOF && i < 10)
        s[i++] = c;
    s[i] = '\0';
    printf("\t... result: \"%s\"\n", s);

    return 0;
}
