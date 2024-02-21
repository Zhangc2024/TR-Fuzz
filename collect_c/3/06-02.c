#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define YES 1
#define NO 0

struct tnode{
	char *word;
	int match;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtreex(struct tnode *, char *, int, int *);
void treeprintx(struct tnode *);
struct tnode *talloc(void);
char *strdupx(char *);

int getword(char *, int);
int getch(void);
void ungetch(int);

main(int argc, char *argv[])
{
	struct tnode *root;
	char word[MAXWORD+1];
	int found = NO;
	int num;
	
	num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0]+1) : 6;
	printf("%d\n", num);
	root = NULL;
	while (getword(word, MAXWORD) != EOF){
		printf("%d %d %d\n", strlen(word) >= num, strlen(word), num);
		if (isalpha(word[0]) && strlen(word) >= num)
			root = addtreex(root, word, num, &found);
		found = NO;	
	}
	treeprintx(root);
	return 0;
}

struct tnode *talloc(void);
int compare(char *, struct tnode *, int, int *);

struct tnode *addtreex(struct tnode *p, char *w, int num, int *found)
{
	int cond;
	
	if (p == NULL) {
		p = talloc();
		p->word = strdupx(w);
		p->match = *found;
		p->left = p->right = NULL;
	} else if ((cond = compare(w, p, num, found)) < 0)
		p->left = addtreex(p->left, w, num, found);
	else if (cond > 0)
		p->right = addtreex(p->right, w, num, found);
	return p;
}

int compare(char *s, struct tnode *p, int num, int *found)
{
	int i;
	char *t = p -> word;
	
	for (i = 0; *s == *t; i++, s++, t++)
		if (*s == '\0')
			return 0;
		
	if (i >= num) {
		*found = YES;
		p->match = YES;
	}

	return *s - *t;
}

void treeprintx(struct tnode *p)
{
	if (p != NULL){
		treeprintx(p->left);
		if (p->match)
			printf("%s\n", p->word);
		treeprintx(p->right);	
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
	printf("> %s\n", word);
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
