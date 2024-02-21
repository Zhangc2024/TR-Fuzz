// The idea is from the c answer book.

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define YES 1
#define NO 0
// The default first number of chars we compare for each strings
#define NUM 6
#define BUFSIZE 100
// buffer for ungetch
char buf[BUFSIZE];
// next free position in buf
int bufp = 0;

/* get a (possibly pushed back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

/* getword: get next word or character from input */
int getword(char *word, int lim) {
    int c;
    char *w = word;
    while (isspace(c=getch())) {
        ;
    }
    if (c != EOF) {
        *w++ = c;
    }
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++) {
        // Will read next char to w even if next char
        // isn't alpha nor number, since it's executed
        // by (*w = getch()) as condition. That's the 
        // reason we need ungetch to get the char that's
        // not alpha nor number back to buffer.
        if(!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

// the tree node
struct tnode {
    // pointer to the text
    char *word;
    // if first num chars match to the current node
    int match;
    // left child
    struct tnode *left;
    // right child
    struct tnode *right;
};

// talloc: make a tnode
struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

// make a dupliate of s
char *myStrdup(char *s) {
    char *p;

    // +1 for '\0'
    p = (char *) malloc(strlen(s)+1);
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}

// treeprint: in-order print matched elements of tree p
void treePrintMatch(struct tnode *p) {
    if (p != NULL) {
        treePrintMatch(p->left);
        if (p->match) {
            printf("%s\n", p->word);
        }
        treePrintMatch(p->right);
    }
}

// treeprint: in-order print of tree p
void treePrint(struct tnode *p) {
    if (p != NULL) {
        treePrint(p->left);
        printf("%s\n", p->word);
        treePrint(p->right);
    }
}

// found is passed as a pointer to modify original value.
int compare (char *s, struct tnode *p, int num, int *found) {
    int i;
    char *t = p->word;
    for (i = 0; *s == *t; s++, t++, i++) {
        // Equal, but in caller we don't do anything, since
        // it's already in the tree.
        if (*s == *t == '\0') {
            return 0;
        }
    }
    if (i >= num) {
        // found is for the word, so that we know this is a matched word
        *found = YES;
        // update the node, since we already got a similar one with the node
        p->match = YES;
    }
    // Allocate the word's position lexicographically
    return *s - *t;
}

// addtree: add a node with w, at or below p
struct tnode *addtree(struct tnode *p, char *w, int num, int *found) {
    int cond;

    // a new word has arrived
    if (p == NULL) {
        // make a new node
        p = talloc();
        p->word = myStrdup(w);
        p->match = *found;
        p->left = p->right = NULL;
    } else if ((cond = compare(w, p, num, found)) < 0) {
        p->left = addtree(p->left, w, num, found);
    } else if (cond > 0) {
        p->right = addtree(p->right, w, num, found);
    }
    return p;
}

// word frequency count 
int main (int argc, char *argv[]) {
    struct tnode *root;
    char word[MAXWORD];
    int found = NO;
    int num;

    num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0]+1) : NUM;

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word, num, &found);
        }
        found = NO;
    }
    printf("Originial tree in-oder: \n");
    treePrint(root);
    printf("Matched elements in tree in-oder: \n");
    treePrintMatch(root);
    return 0;
}
// Could read from another c program: ./Exercise_6_2 -10 < testStruct.c