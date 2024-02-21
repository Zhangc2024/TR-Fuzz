#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
struct tnode{
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
char *strdupx(char *);
int getch(void);
void ungetch(int);

main()
{
	struct tnode *root;
	char word[MAXWORD];
	
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);
	treeprint(root);
	return 0;
}

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;
	
	if (p == NULL) {
		p = talloc();
		p->word = strdupx(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

void treeprint(struct tnode *p)
{
	if (p != NULL){
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);	
	}
}

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdupx(char *s)
{
	char *p;
	
	p =  (char *) malloc(strlen(s)+1);
	if (p != NULL){
		strcpy(p,s);
		return p;	
	}
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c, d;
	char *w = word;
	
	while (isspace(c = getch()))
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
