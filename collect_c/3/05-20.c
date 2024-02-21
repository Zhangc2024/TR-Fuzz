#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };
enum { NO, YES};

void dcl(void);
void dirdcl(void);
void errmsg(char *);
int gettoken(void);

int tokentype;	/* type of last token */
char token[MAXTOKEN];		/* last token string */
char name[MAXTOKEN];		/* identifier name 	 */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */
char out[MAXTOKEN];
int prevtoken;

int prevtoken = NO;

main()
{
	while(gettoken() != EOF){
		strcpy(datatype, token);
		out[0] = '\0';
		dcl();
		if (tokentype != '\n')
			printf("syntax error %d\n", tokentype);
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}

int gettoken(void)
{
	int c, getch(void);
	void ungetch(int);
	char *p = token;
	
	if (prevtoken == YES) {
		prevtoken = NO;
		//printf("prev %d \n", tokentype);
		return tokentype;
	}
	
	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';	
		}
	} else if ( c== '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if ( isalpha(c) ) {
		for ( *p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else
		return tokentype = c;
}

/* dcl: parse a declarator */
void dcl(void)
{
	int ns;
	
	for (ns = 0; gettoken() == '*'; )
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " pointer to");
}

/* dirdcl: parse a direct declaration */
void dirdcl(void)
{
	int type;
	void parmdcl(void);
	
	if (tokentype == '(') {
		dcl();
		if (tokentype != ')')
			errmsg("error: missing)\n");
	} else if (tokentype == NAME) {
		if (name[0] == '\0')
			strcpy(name, token);	
	} else
		prevtoken = YES;
	
	while ((type = gettoken()) == PARENS || type == BRACKETS || type == '(')
		if (type == PARENS)
			strcat (out, "function returning");
		else if (type == '('){
			strcat (out, "function expecting");
			parmdcl();
			strcat(out, " and returning");			
		} else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
}

/* errmsg: print error message and indicate avail. token */
void errmsg(char *msg)
{
	//printf("%s", msg);
	prevtoken = YES;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;          /* next free position in buff */

int getch(void)        /* get a (possibly pushed back) character */
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

void ungets(char *s)   /* push character back on input */
{
	int len = strlen(s);
	
	while (len > 0)
    	ungetch(s[--len]);
}
