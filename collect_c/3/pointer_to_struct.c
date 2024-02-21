/* let's write teh keyword-counting  program again using pointers instead of
 * array indices
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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


#define NKEYS (sizeof keytab / sizeof(keytab[0]))

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);

/* count C keywords; pointer version */
int main(){
    char word[MAXWORD];
    struct key *p;

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ( (p = binsearch(word, keytab, NKEYS)) != NULL)
                p->count++;
    for (p = keytab; p < keytab + NKEYS; p++)
        if (p->count > 0)
            printf("%4d %s\n", p->count, p->word);
    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
struct key *binsearch(char *word, struct key *tab, int n){
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low < high) {
        mid = low + (high - low) /2;
        /* the computation of the middle element can no longer be
         *      mid = (low + high) /2
         * because addition of pointers is illegal. Subtraction is legal,
         * however, so
         *      high - low
         * is the number of elements
         */
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return NULL;
}

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
