#include <stdio.h>
#include <ctype.h>
#define SIZE 10

main(){
	int i, n, array[SIZE], getint(int *);

	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;

	for (i = 0; i < 10; ++i){
		printf("%d ", array[i]);
	}
}

int getch(void);
void ungetch(int);

int getint(int *pn)
{
	int c, d, sign;
	
	while(isspace(c = getch()))
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if ( c == '+' || c== '-'){
		d = c;
		if (!isdigit(c = getch())){
			if (c != EOF)
				ungetch(c);
			ungetch(d);
			return d;
		}
	}

	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
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
