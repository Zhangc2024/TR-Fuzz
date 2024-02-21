#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>

#define MAXWORD	100

typedef struct tnode {
	char *word;
	bool match;
	struct tnode *left;
	struct tnode *right;
} tnode;

tnode* talloc();
void tfree(tnode*);

tnode* xaddtree(tnode*, char*, bool*);
void xprinttree(tnode *p);
int nstrcmp(char word[], tnode*, bool *found);

int getword(char*, int);
int getch();
void ungetch(int);
void error(char*);

long num = 0;

int main(int argc, char *argv[]) {
	tnode *root = NULL;
	char word[MAXWORD];
	int c;
	bool found = false;
	if (argc >= 2 && isdigit((*++argv)[0]))
		num = strtol(*argv, NULL, 0);

	while ((c = getword(word, MAXWORD)) != EOF) {
		if (isalpha(c) && strlen(word) >= num)
			root = xaddtree(root, word, &found);
		found = false;
	}
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
tnode* xaddtree(tnode *p, char *word, bool *found) {
	if (!p) {
		/*	Create a new Node	*/
		tnode *np;
		if (!((np = talloc()) && (np->word = strdup(word))))
			error("Not Enough Memory.");

		np->left = np->right = NULL;
		np->match = *found;
		return np;
	}

	int cmp;
	if ((cmp = nstrcmp(word, p, found)) > 0)
		p->right = xaddtree(p->right, word, found);
	else if (cmp < 0)
		p->left = xaddtree(p->left, word, found);

	return p;
}

/*	Print words which are found in left-mid-right order	*/
void xprinttree(tnode *p) {
	if (p) {
		xprinttree(p->left);
		if (p->match)
			printf("%s\n", p->word);
		xprinttree(p->right);
	}
}

/*	Compare the word and the node's word, just like stdlib strcmp
 *  if two strings are not equal and there's a match, set match and found to true
 */
int nstrcmp(char word[], tnode *p, bool *found) {
	char *s, *t;
	int i, res;
	s = word;
	t = p->word;

	for (i = 0; s[i] == t[i] && s[i]; i++)
		;
	res = s[i] - t[i];

	if (res && i >= num)
		p->match = *found = true;
	return res;

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
