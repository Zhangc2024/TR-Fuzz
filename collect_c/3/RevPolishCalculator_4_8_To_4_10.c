/* Example in Section 4.3
   Exercise 4-8
 */

#include <stdio.h>
#include <stdlib.h> /* for atof */

#define MAXOP  100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []); 
int getopfromline(char []); 
void push(double); 
double pop(void); 
void printstack(); 

/* reverse Polish calculator */ 
int main () 
{
    int type; 
    double op2; 
    char s[MAXOP]; 

    while ((type = getopfromline(s)) != EOF) {
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
		printf("error:zero divisor\n"); 
	    break; 
	case '\n':
	    printf("\t%.8g\n", pop()); 
	    break; 
	default:
	    printf("error: unknown command %s\n", s); 
	}
    }
    return 0; 
}

/* push and pop */ 
#define MAXVAL 100  /* maximum depth of val stack */ 

int sp = 0;         /* next free stack position */ 
double val[MAXVAL]; /* value stack */ 

/* function to debug the stack */
void printstack()
{
    printf("Current stack:\t"); 
    for (int i = 0; i < sp; i++)
	printf("%f\t", val[i]); 
    printf("\n"); 
}


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

/* getop: get next operator or numeric operand */
#include <ctype.h>
#define LINE_LEN 1024
#define IN 1
#define OUT 0

int getch(void); 
void ungetch(int); 

int getline(char [], int); 

char line[LINE_LEN]; 
int idx = 0;           /* index of current char */
int end = 0;           /* indicator if the current line has EOF */
int state = OUT; 

int getop(char s[])
{
    int i, c; 
	
    while ((s[0] = c = getch()) == ' ' || c == '\t')
	; 

    s[1] = '\0'; 
    if (!isdigit(c) && c != '.')
	return c; /* not a number */
    i = 0; 
    if (isdigit(c)) /* collect integer part */
	while (isdigit(s[++i] = c = getch()))
	    ;
    if (c == '.')
	while (isdigit(s[++i] = c = getch()))
	    ; 
    s[i] = '\0'; 
    if (c != EOF)
	ungetch(c); 
    return NUMBER; 
}

/* getopfromline: return the type of the op and store the attribute
   in s. Exercuse 4-10. 
 */
int getopfromline(char s[])
{
    int i, c;

    if (state == OUT) {
	state = IN; 
	end = getline(line, LINE_LEN); 
	idx = 0; 
    }

    while ((s[0] = c = line[idx++]) == ' ' || c == '\t')
	; 

    s[1] = '\0'; 
    if (!isdigit(c) && c != '.') {	 
	if (isprint(c) && c != '\n')
	    return c; /* not a number */
	if (end) {
	    state = OUT; 
	    return EOF; 
	}
	if (c == '\n')
	    state = OUT;
	return c;     /* not a number */
    }

    i = 0; 
    if (isdigit(c)) /* collect integer part */
	while (isdigit(s[++i] = c = line[idx++]))
	    ;
    if (c == '.')
	while (isdigit(s[++i] = c = line[idx++]))
	    ; 
    s[i] = '\0';  
    return NUMBER;    
}

/* getline: read a line into s, return 1 if reaches EOF on current 
   line.  
 */
int getline(char s[], int lim)
{
    int c, i, end; 
    
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
	s[i] = c; 
    if (c == '\n') {
	s[i] = c; 
	++i; 
    }

    if (c == EOF)
	end = 1; 
    else 
	end = 0; 

    s[i] = '\0';

    return end; 
}

/* getch and ungetch */
#define BUFSIZE 1  /* Exercise 4-8 */
int buf[BUFSIZE];  /* buffer for ungetch  - Exercise 4-9 */
int bufp = 0;      /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar(); 
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
	printf("ungetch: too many characters\n"); 
    else
	buf[bufp++] = c; 
}
