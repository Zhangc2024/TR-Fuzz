#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>

static long num = 1; /*	Current Line Number	*/
static char *nw[] = { "a", "an", "and", "are", "in", "is", "of", "or", "that",
		"the", "this", "to" }; /*	Noise Words	*/

typedef struct LineLinkedList {
	long lnum;
	struct LineLinkedList *next;
} llist;

llist* lalloc();
void lfree(llist*);

llist* addnl(llist*, long);

typedef struct tnode {
	char *word;
	llist *lines;
	struct tnode *left;
	struct tnode *right;
} tnode;

tnode* talloc();
void tfree(tnode*);

tnode* xaddtree(tnode*, char*);
void xprinttree(tnode *p);

int getword(char*, int);
bool isnw(char*);

int getch();
void ungetch(int);
void error(char*);

#define MAXWORD	100
#define NWLEN (sizeof nw / sizeof (char*))

int main(int argc, char *argv[]) {
	tnode *root = NULL;
	char word[MAXWORD];
	int c;

	while ((c = getword(word, MAXWORD)) != EOF)
		if (isalpha(c) && !isnw(word))
			root = xaddtree(root, word);

	xprinttree(root);
	tfree(root);
	return EXIT_SUCCESS;
}

int getword(char *word, int lim) {
	void incmt(int);

	int c, d, type;
	char *w = word; /*	Current Pointer	*/

	/*	Consume Blanks	*/
	while (isspace(c = getch()))
		/*	Count New Line	*/
		if (c == '\n')
			num++;

	/*	Match Patterns	*/
	type = c;

	if (isalpha(c) || c == '#' || c == '_') {
		/*	a word	*/
		for (*w++ = c; --lim > 1 && (isalnum(c = getch()) || c == '_');)
			*w++ = c;

		if (lim != 1)
			ungetch(c);

	} else if (c == '/') {
		if ((c = getch()) == '*' || c == '/')
			/*	A Comment	*/
			incmt(c);
		else
			ungetch(c);
	} else if (c == '\'' || c == '"') {
		/*	A String	*/
		d = c;
		while (--lim > 0 && (c = getch()) != d && c != EOF)
			if (c != '\\' || (c = getch()) != EOF)
				*w++ = c;
	}

	*w = '\0';
	return type;
}

/*	Add a new node of the given word to the tree if the word doesn't exist in the tree
 * Otherwise set the match of the node withe the word to true	*/
tnode* xaddtree(tnode *p, char *word) {
	if (!p) {
		/*	Create a new Node	*/
		tnode *np;
		llist *nl;
		if (!((np = talloc()) && (np->word = strdup(word))))
			error("Not Enough Memory.");

		/*	Create new line	Linked List */
		nl = NULL;
		nl = addnl(nl, num);

		np->lines = nl;
		np->left = np->right = NULL;
		return np;
	}

	int cmp;
	if ((cmp = strcmp(word, p->word)) > 0)
		p->right = xaddtree(p->right, word);
	else if (cmp < 0)
		p->left = xaddtree(p->left, word);
	else
		p->lines = addnl(p->lines, num);
	return p;
}

/*	Print words and the line numbers it appear in inorder	*/
void xprinttree(tnode *p) {
	llist *lptr; /*	Line Pointer	*/
	if (p) {
		xprinttree(p->left);
		printf("%10s: ", p->word);
		for (lptr = p->lines; lptr; lptr = lptr->next)
			printf("%4ld", lptr->lnum);
		putchar('\n');
		xprinttree(p->right);
	}
}

/*	Allocate a new tree node	*/
tnode* talloc() {
	return (tnode*) malloc(sizeof(tnode));
}

/*	Free memory of tree	*/
void tfree(tnode *p) {
	if (p) {
		free(p->word);
		lfree(p->lines);
		tfree(p->left);
		tfree(p->right);
	}

	free(p);
}

/*	Add a new node to the linked list */
llist* addnl(llist *l, long n) {
	if (!l) {
		if (!(l = lalloc()))
			error("Not Enough Memory.");
		l->lnum = n;
		l->next = NULL;

		return l;
	}

	if (l->lnum != n)
		l->next = addnl(l->next, n);
	return l;
}

/*Allocate a new Linked List	*/
llist* lalloc() {
	return (llist*) malloc(sizeof(llist));
}

/*	Free memory of a linked list	*/
void lfree(llist *lp) {
	if (lp)
		lfree(lp->next);
	free(lp);
}

/*	whether a word is a noise word	*/
bool isnw(char *s) {
	int binsearch(char*, int lo, int hi);

	return (binsearch(s, 0, NWLEN - 1) == -1) ? false : true;
}

int binsearch(char *s, int lo, int hi) {
	int mid, cmp;
	mid = (lo + hi) / 2;

	if (lo > hi)
		return -1;

	if ((cmp = strcmp(s, nw[mid])) < 0)
		return binsearch(s, lo, mid - 1);
	else if (cmp > 0)
		return binsearch(s, mid + 1, hi);
	else
		return mid;
}

/*	Jump Over a Comment Block	*/
void incmt(int type) {
	assert(type == '*' || type == '/');

	int c, lastc;
	switch (type) {
	case '*':
		// Comment Format  /* ... */
		for (c = getch();
				(lastc = c) != EOF && ((c = getch()) != '/' || lastc != '*');)
			if (lastc == '\n')
				num++;

		break;
	case '/':
		/*	Comment Format // ... \n */
		while ((c = getch()) != '\n' && c != EOF)
			;
		num++;
		break;
	default:
		break;
	}
}

static int lastc;
int getch() {
	int c;
	if (lastc != '\0') {
		c = lastc;
		lastc = '\0';
	} else
		c = getchar();
	return c;
}

void ungetch(int c) {
	assert(!lastc);

	lastc = c;
}

void error(char *msg) {
	perror(msg);
	exit(1);
}
