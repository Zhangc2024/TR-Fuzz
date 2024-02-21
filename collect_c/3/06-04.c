#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define NDISTINCT 1000

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtreex(struct tnode *, char *);
int getword(char *, int);
void sortlist(void);
void treestore(struct tnode *);

struct tnode *talloc(void);

struct tnode *list[NDISTINCT];
int ntn = 0;

/* print distinct words sorted in decreasing order of freq */
main()
{
	struct tnode *root;
	char word[MAXWORD];
	int i;

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtreex(root, word);
	treestore(root);
	sortlist();
	for (i = 0; i< ntn; i++)
		printf("%2d:%20s\n", list[i]->count, list[i]->word);
	return 0;
}

/* treestore: storn in list[] pointers to tree nodes */
void treestore(struct tnode *p)
{
	if (p != NULL) {
		treestore(p->left);
		if (ntn < NDISTINCT)
			list[ntn++] = p;
		treestore(p->right);
	}
}

/* sortlist: sort list of pointers to tree nodes */
void sortlist()
{
	int gap, i, j;
	struct tnode *temp;
	for (gap = ntn/2; gap > 0; gap /= 2)
		for (i = gap; i < ntn; i++)
			for(j = i-gap; j >= 0; j -=gap) {
				if ((list[j]->count) >= (list[j+gap]->count))
					break;
				temp = list[j];
				list[j] = list[j+gap];
				list[j+gap] = temp;
			}
}

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

struct tnode *addtreex(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL) {
		p = talloc();
		p->word = strdup(w);
        p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count += 1;
	else if (cond < 0)
		p->left = addtreex(p->left, w);
	else
		p->right = addtreex(p->right, w);
	return p;
}

int getch(void);
void ungetch(int);

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c, d;
	char *w = word;

	while (isspace(c = getch()) && c != '\n')
		;
	if (c != EOF)
		*w++ = c;
	if (isalpha(c) || c == '_' || c == '#') {
		for (; --lim > 0; w++)
			if (!isalnum(*w = getch()) && *w != '_') {
				ungetch(*w);
				break;
			}
	} else if ( c == '\'' || c == '"') {
		for ( ; --lim > 0; w++)
			if ((*w = getch()) == '\\')
				*++w = getch();
			else if (*w == c) {
				w++;
				break;
			} else if (*w == EOF)
				break;
	} else if ( c == '/' )
		if ((d = getch()) == '*')
			c = comment();
		else
			ungetch(d);

	*w = '\0';
	return c;
}

/*comment: skip over comment and return a character */
int comment(void)
{
	int c;
	while ((c = getch()) != EOF)
		if (c == '*')
			if ((c = getch()) == '/')
				break;
			else
				ungetch(c);
	return c;
}
#define BUFSIZE 100

char buf[BUFSIZE]; 		/* buffer for ungetch */
int bufp = 0;			/* next free position in buff */

int getch(void)			/* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)   /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
