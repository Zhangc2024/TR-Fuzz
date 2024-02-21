#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

void dcl(void);
void errmsg(char *);
void dclspec(void);

int typespec(void);
int typequal(void);
int comparex(const void *, const void *);
int gettoken(void);

extern int tokentype;	/* type of last token */
extern char token[];		/* last token string */
extern char name[];		/* identifier name 	 */
extern char datatype[]; /* data type = char, int, etc. */
extern char out[];
extern int prevtoken;

/* parmdcl: parse a parameter declarator */
void parmdcl(void)
{
	do {
		dclspec();
	} while (tokentype == ',');
	if (tokentype != ')')
		errmsg("missing ) in parameter declaration\n");
}

/* dclspec: declaration specification */
void dclspec(void)
{
	char temp[MAXTOKEN];
	
	temp[0] = '\0';
	gettoken();
	do {
		if(tokentype != NAME) {
			prevtoken = YES;
			dcl();
		} else if (typespec() == YES) {
			strcat(temp, " ");
			strcat(temp, token);
			gettoken();
		} else if (typequal() == YES) {
			strcat(temp, " ");
			strcat(temp, token);
			gettoken();
		} else
			errmsg("unknown type in parameter list\n");
			break;
	} while (tokentype != ',' && tokentype != ')');
	strcat(out, temp);
	if (tokentype == ',')
		strcat(out, ",");
}

/* typespec: return YES if token is a type-specifier */
int typespec(void)
{
	static char *types[] = {
		"char",
		"int",
		"void"
	};
	char *pt = token;
	
	if ( bsearch(&pt, types, sizeof(types)/sizeof(char *), sizeof(char *), comparex) == NULL )
		return NO;
	else 
		return YES;
}

/* typequal: return YES if token is a type-qualifier */
int typequal(void)
{
	static char *typeq[] = {
		"const",
		"volatitle"	
	};
	
	char *pt = token;
	
	if ( bsearch( &pt, typeq, sizeof(typeq)/sizeof(char *), sizeof(char *), comparex ) == NULL )
		return NO;
	else
		return YES;
}

/* comparex: comparex two strings for bsearch */
/* https://cboard.cprogramming.com/c-programming/157885-k-r-exercise-5-20-bsearch-error-when-compiled.html */
int comparex(const void *s, const void *t)
{
    char **chs;
    char **cht;
    chs = (char **) s;
    cht = (char **) t;
    return strcmp(*chs, *cht);
}
