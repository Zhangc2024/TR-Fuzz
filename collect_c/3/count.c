#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct tnode {
	char *word;
	long count;
	struct tnode *left;
	struct tnode *right;
};

#define MAXWORD 100

int getword(char *s, int max);
struct tnode *addtree(struct tnode *, char *w);
void printtree(struct tnode*);

int main(int argc, char const *argv[])
{
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD) != EOF) {
		root = addtree(root, word);
	}
	printtree(root);

	return 0;
}

int getword(char *s, int max) {
	char *p = s;
	int c;
	while ((c = getchar()) != EOF && isspace(c))
		;

	if (c != EOF) {
		*p++ = c;
	}

	while (max-- > 0 && (c = getchar()) != EOF && !isspace(c)) {
		*p++ = c;
	}
	*p = '\0';

	return c;
}

struct tnode *addtree(struct tnode *n, char *word) {
	int cond;
	char *sdup(char *);

	if (n == NULL) {
		n = (struct tnode *)malloc(sizeof(struct tnode));
		n->word = sdup(word);
		n->count = 1;
		n->left = n->right = NULL;
	} else if ((cond = strcmp(word, n->word)) == 0) {
		n->count++;
	} else if (cond < 0) {
		n->left = addtree(n->left, word);
	} else {
		n->right = addtree(n->right, word);
	}

	return n;
}

char *sdup(char *str) {
	char *p = (char *)malloc(strlen(str) + 1);
	if (p != NULL) {
		strcpy(p, str);	
	}
	
	return p;
}

void printtree(struct tnode *n) {
	if (n == NULL) {
		return;
	}

	printtree(n->left);
	printf("%4ld %s\n", n->count, n->word);
	printtree(n->right);
}
