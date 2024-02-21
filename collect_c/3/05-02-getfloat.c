#include <stdio.h>
#include <ctype.h>
#define SIZE 10

main(){
	int i, n, getfloat(float *);
	float array[SIZE];

	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
		;

	for (i = 0; i < 10; ++i){
		printf("%f ", array[i]);
	}
}


int getch(void);
void ungetch(int);

/* getfloat: get next floating-point number from input */
int getfloat(float *pn)
{
	int c, sign;
	float power;
	
	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c !=EOF && c != '+' && c != '-' && c != '.'){
		ungetch(c);
		return 0;
	}
	
	sign = (c == '-') ? -1 : 1;
	
	if (c == '+' || c == '-')
		c = getch();
	
	for (*pn = 0.0; isdigit(c); c = getch()){
		*pn = 10.0 * *pn + (c - '0');
	}
	
	if (c == '.')
		c = getch();
	
	for (power = 1.0; isdigit(c); c = getch()){
		*pn = 10.0 * *pn + (c - '0');
		power *= 10.0;
	}
	
	*pn *= sign / power;
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
