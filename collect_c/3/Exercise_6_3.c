// Most of the codes are from the c answer book
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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
    // isspace includes newline ('\n')
    while (isspace(c=getch()) && c != '\n') {
        ;
    }
    // EOF is not a char. Check it later.
    if (c != EOF) {
        *w++ = c;
    }
    // And caller will check word[0] to see if it's alpha
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++) {
        if(!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

struct linkedlist {
    int lineNum;
    struct linkedlist *next;
};

// the tree node
struct tnode {
    // pointer to the text
    char *word;
    // number of occurences
    struct linkedlist *lines;
    // left child
    struct tnode *left;
    // right child
    struct tnode *right;
};

// lalloc: make a linkedlist node
struct linkedlist *lalloc(void) {
    return (struct linkedlist *) malloc(sizeof(struct linkedlist));
}

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
    struct linkedlist *tmp;
    if (p != NULL) {
        treeprint(p->left);
        printf("%10s: ", p->word);
        for (tmp = p->lines; tmp != NULL; tmp = tmp->next) {
            printf("%4d ", tmp->lineNum);
        }
        printf("\n");
        treeprint(p->right);
    }
}

// addln: add a line number to the linkedlist
void addln(struct tnode *p, int num) {
    struct linkedlist *tmp;
    tmp = p->lines;
    while (tmp->next != NULL && tmp->lineNum != num) {
        tmp = tmp->next;
    }
    if (tmp->lineNum != num) {
        tmp->next = lalloc();
        tmp->next->lineNum = num;
        tmp->next->next = NULL;
    }
}


// addtree: add a node with w, at or below p
struct tnode *addtree(struct tnode *p, char *w, int lineNum) {
    int cond;

    // a new word has arrived
    if (p == NULL) {
        // make a new node
        p = talloc();
        p->word = myStrdup(w);
        p->lines = lalloc();
        p->lines->lineNum = lineNum;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        addln(p, lineNum);
    } else if (cond < 0) {
        // less than into left subtree
        p->left = addtree(p->left, w, lineNum);
    } else {
        p->right = addtree(p->right, w, lineNum);
    }
    return p;
}

bool isNoise(char *w) {
    static char *nw[] = {
        "a",
        "an",
        "and",
        "that",
        "the",
        "this"
    };
    int cond, mid;
    int low = 0;
    int high = sizeof(nw) / sizeof(char *) - 1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if ((cond = strcmp(w, nw[mid])) < 0) {
            high = mid - 1;
        } else if (cond > 0) {
            low = mid + 1;
        } else {
            return true;
        }
    }
    return false;
}

// word frequency count 
int main () {
    struct tnode *root;
    char word[MAXWORD];
    int lineNum = 1;

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) && !isNoise(word)) {
            root = addtree(root, word, lineNum);
        } else if (word[0] == '\n') {
            lineNum++;
        }
    }
    treeprint(root);
    return 0;
}