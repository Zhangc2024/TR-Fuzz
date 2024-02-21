#include <stdio.h>
#include <string.h>
#include <math.h>  /* for atof() */
#include <ctype.h>

#define BUFSIZE 100
#define MAXOP 100    /* max size of operand or operator */
#define NUMBER '0'   /* signal that a number was found */
#define MAXVAL 100    /* maximum depth of val stack */

int getop(char[]);
void push(double);
double pop(void);

/* reverse Polish calculator */
main ()
{
    int i, type, var = 0;
    double op2, v;
    char s[MAXOP];
    double variable[26];

	for ( i = 0; i < 26; i++)
		variable[i] = 0.0;
    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
        	op2 = pop();
        	if (op2 != 0.0)
        		push (fmod(pop(), op2));
        	else
        		printf ("error: zero divisor\n");
        	break;
        case '=':
        	pop();
        	if (var >= 'A' && var <= 'Z')
        		variable[var - 'A'] = pop();
        	else
        		printf("error: no variable name\n");
        	break;
        case '\n':
        	v = pop();
            printf("\t%.8g\n", v);
            break;
        default:
        	if (type >= 'A' && type <= 'Z')
        		push(variable[type - 'A']);
        	else if (type == 'v')
        		push(v);
        	else
	            printf("error: unknown command %s\n", s);
            break;
        }
        var = type;
    }
    return 0;
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i,c;
	void ungetch(int c);
	
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;     /* not a number */
    i = 0;
    if (c == '-')
    	if (isdigit(c = getch()) || c == '.')
    		s[++i] = c; 
    	else {
    		if (c != EOF)
    		    ungetch(c);
    		return '-';
		}
    if (isdigit(c))   /* collect integer part */
        while ( isdigit(s[++i] = c = getch()) )
            ;
    if (c == '.')     /* collect fraction part */
        while ( isdigit(s[++i] = c = getch()) )
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

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

int sp = 0;           /* next free stack position */
double val[MAXVAL];  /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
