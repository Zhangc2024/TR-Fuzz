#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
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
    // number of occurences
    int count;
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

// treeprint: in-order print of tree p
void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

// addtree: add a node with w, at or below p
struct tnode *addtree(struct tnode *p, char *w) {
    int cond;

    // a new word has arrived
    if (p == NULL) {
        // make a new node
        p = talloc();
        p->word = myStrdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        // repeated word
        p->count++;
    } else if (cond < 0) {
        // less than into left subtree
        p->left = addtree(p->left, w);
    } else {
        p->right = addtree(p->right, w);
    }
    return p;
}

// word frequency count 
int main () {
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }
    treeprint(root);
    return 0;
}