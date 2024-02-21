/*
 * Reverses input lines one at a time
 */

// The following definition change is needed to allow the use of getline() in this
// example without having to call it something else.
// c.f. http://stackoverflow.com/questions/37474117/how-to-implement-custom-versions-of-the-getline-function-in-stdio-h-clang-os-x

#undef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L

// Includes

#include <stdio.h>

// Definitions

#define MAXLINE 10000 /* Note: MAXLINE includes terminating newline and null characters */

/*
 * swap macro: swaps two values of a specified type
 */

#define swap(t, x, y) \
    {                 \
        t _temp;      \
        _temp = x;    \
        x = y;        \
        y = _temp;    \
    }


/* getbigline: read an aribitrarily long line placing as much as
 * possible into 's' and returning the full length
 */

static size_t getline(char s[], size_t lim) {

    char   c;
    size_t i = 0;

    while (--lim > 0 && (c = (char)getchar()) != (char)EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}

/*
 * reverse: reverses a line
 */

static void reverse(char s[]) {

    size_t i = 0;
    size_t j = 0;

    // Find end of string
    while (s[i] != '\0')
        ++i;
    --i;

    // Leave terminating newline in place if they exist
    if (i > 0 && s[i] == '\n')
        --i;

    // Bail out if there is nothing left to do (one or zero characters)
    // NOTE: If we don't do this, we will segment fault
    if (i < 1)
        return;

    // Reverse remaining in place
    while (j < i) {
        swap(char, s[i], s[j]);
        i--;
        j++;
    }
}

/* Main */

int main(void) {

    char   line[MAXLINE] = "";

    while (getline(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s\n", line);
    }

    return 0;
}
