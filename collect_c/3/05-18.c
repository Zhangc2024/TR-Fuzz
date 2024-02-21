#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

void dcl(void);
void dirdcl(void);
int gettoken(void);
void errmsg(char *msg);

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
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
		printf("prev %d \n", tokentype);
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

void dcl(void)
{
	int ns;
	
	for (ns = 0; gettoken() == '*';)
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " pointer to");
}

void dirdcl(void)
{
	int type;
	
	if (tokentype == '(') {
		dcl();
		if (tokentype != ')')
			errmsg("error: missing )\n");
	} else if ( tokentype == NAME )
		strcpy(name, token);
	else
		errmsg("error: expected name or (dcl)\n");
	while ((type = gettoken()) == PARENS || type == BRACKETS)
		if (type == PARENS)
			strcat(out, " function returning");
		else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
}

void errmsg(char *msg)
{
	printf("%s", msg);
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
