#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>

#define MAXWORD	100
#define MAXNOD 1000
typedef struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
} tnode;

static tnode *nsptr[MAXNOD];
int ntn = 0; /*	Current Number of Nodes	*/

tnode* talloc();
void tfree(tnode*);

tnode* xaddtree(tnode*, char*);

int getword(char*, int);

int getch();
void ungetch(int);
void error(char*);

void ssort(void**, int (*)(void*, void*));

int main(int argc, char *argv[]) {

	tnode *root = NULL;
	char word[MAXWORD];
	int c, i, cntcmp(tnode*, tnode*);

	while ((c = getword(word, MAXWORD)) != EOF)
		if (isalpha(c))
			root = xaddtree(root, word);

	ssort((void**) nsptr, (int (*)(void*, void*)) cntcmp);
	for (i = 0; i < ntn; i++)
		printf("%d\t%10s\n", nsptr[i]->count, nsptr[i]->word);

	tfree(root);
	return EXIT_SUCCESS;
}

int getword(char *word, int lim) {
	void incmt(int);

	int c, d, type;
	char *w = word; /*	Current Pointer	*/

	/*	Consume Blanks	*/
	while (isspace(c = getch()))
		;
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
		if (!((np = talloc()) && (np->word = strdup(word))))
			error("Not Enough Memory.");

		/*	Add to nodes array	*/
		nsptr[ntn++] = np;

		np->left = np->right = NULL;
		np->count = 1;

		return np;
	}

	int cmp;
	if ((cmp = strcmp(word, p->word)) > 0)
		p->right = xaddtree(p->right, word);
	else if (cmp < 0)
		p->left = xaddtree(p->left, word);
	else
		p->count++;
	return p;
}

/*	Allocate a new tree node	*/
tnode* talloc() {
	return (tnode*) malloc(sizeof(tnode));
}

/*	Free memory of tree	*/
void tfree(tnode *p) {
	if (p) {
		free(p->word);
		tfree(p->left);
		tfree(p->right);
	}

	free(p);
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
			;
		break;
	case '/':
		/*	Comment Format // ... \n */
		while ((c = getch()) != '\n' && c != EOF)
			;
		break;
	default:
		break;
	}
}

int cntcmp(tnode *t1, tnode *t2) {
	int cmp;
	if ((cmp = t1->count - t2->count) > 0)
		return 1;
	else if (cmp < 0)
		return -1;
	else
		return 0;
}

/*	Shell Sort	*/
void ssort(void **ar, int (*comp)(void*, void*)) {
	int i, j, k, gap;
	void *tmp;

	for (gap = ntn / 2; gap > 0; gap /= 2)
		for (i = gap; i < ntn; i++) {
			for (j = i - gap; j >= 0 && comp(ar[i], ar[j]) < 0; j -= gap)
				;
			tmp = ar[i];
			for (k = i - gap; k > j; k -= gap)
				ar[k + gap] = ar[k];
			ar[k + gap] = tmp;
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
