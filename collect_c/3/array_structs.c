/* consider writing a program to count the occurrences of each C keyword */

#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAXWORD 100

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0,
};

//#define NKEYS (sizeof keytab / sizeof(struct key))
#define NKEYS (sizeof keytab / sizeof(keytab[0]))
/* the 2nd version has an advantage that it does not need to be changed if the
 * type changes
 */

int getword(char *, int);
int binsearch(char *, struct key *, int);

/* count C keywords */
int main(){
    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;

    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n",
                    keytab[n].count, keytab[n].word);
    return 0;
}

/* NKEYS is the number of keywords in 'keytab'
 * we could count this by hand, but its easier and safer to do it by machine (lol)
 * - The size of the array is the size of one entry times the number of entries
 *   so the size of entries is just
 *
 *          size of keytab / size of struct key
 *
 * - C provides a compile-time unary operator called 'sizeof' that can be used
 *   to compute the size of any object.
 *   The expressions
 *
 *          sizeof object
 *
 *   and
 *
 *          sizeof (type name)
 *
 *   yield an integer equal to the size of the specified object or type in bytes
 */

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n){
    int cond;
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    while (low <= high){
        mid = (low + high)/2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

/* - since the structure keytab contains set of names, it is easiest to make it
 *   an external variable and initialize it once and for all when it is defined.
 * - The initializers are listed in pairs corresponding to the structure
 *   members. It would be more precise to enclose the initializers for each
 *   "row" or structure in braces like
 *
 *          {"auto", 0 },
 *          {"break", 0 },
 *          {"case", 0 },
 *
 *   but inner braces are not necessary when the initializers are simple
 *   variables or character strings and when all are present
 */

/* getword: get next word or character from input */
int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (isalpha(c)) {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++)
        if (!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

/* isspace: used to skip whitespaces
 * isalpha: to identify letters
 * isalnum: to identify letters and digits
 *
 * all are from the standard header <ctype.h>
 */
