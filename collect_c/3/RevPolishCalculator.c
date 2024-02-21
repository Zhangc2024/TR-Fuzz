/* Example in Section 4.3
   Exercise 4-3
   Exercise 4-4: For exercise 4-4, the following capital case letters
   are introduced for commands
   - 'T' for printing top of stack
   - 'D' for duplicating top of stack
   - 'S' for swaping the top two elements
   - 'C' for clearing the stack
   Exercise 4-5: For exercise 4-5, the following commands are added
   - 'SIN': calculates sin of x, the synax is 'x SIN'
   - 'EXP': calculates exp(x) with the syntax 'x EXP'
   - 'POW': calculates pow(x) with the syntax 'x y POW'
   Exercise 4-6: Adding twenty-six variables with lower case letter 
   as names. The syntax is the following
   - to assign a value to a variable use
     value variable<-
     For example, to assign variable 'a' value 3.14, use
     3.14 a<- 
   - to use the value already assigned, use the name of the variable
     for example, to use 'a', which has value 3.14, use
     a 2 *
     this gives 6.28
   - using an uninitialized variable causes undefined behaviour. 
   - variable 'RP' is the recently printed value. 
 */

#include <stdio.h>
#include <stdlib.h> /* for atof */
#include <math.h>   /* for Exercise 4-5 */

#define MAXOP  100  /* max size of operand or operator */
#define NUMBER '0'

#define VAR 257
#define ASSIGN 258
#define RECENTPRINT 259

#define TOP 'T'
#define DUPLICATE 'D'
#define SWAPTOP 'S'
#define CLEAR 'C'

#define ASSN "<-"  /* pattern for assignment operation */
#define RECP "P"   /* pattern for recent print value */
#define PSIN "IN"  /* define key word pattern for SIN */
#define PEXP "XP"  /* key word pattern for EXP */
#define PPOW "OW"  /* key word pattern for POW */

#define SIN 260
#define EXP 261
#define POW 262

/* functions that load the next valid token */
int getop(char []); 

/* functions that manipulate the stack */
void push(double); 
double pop(void); 
double top(void); 
void duplicate(void); 
void swaptop(void);
void clear(void); 

/* functions that manages the variable table */
void setvar(char, double); 
void setrecentprint(double);
double getvar(char); 
double getrecentprint(); 

/* functions for debugging */
void printstack(); 
void printbuf(); 

/* reverse Polish calculator */ 
/* Exercise 4-3: added % operator */
int main () 
{
    int type; 
    double op2; 
    char s[MAXOP]; 

    while ((type = getop(s)) != EOF) {
	switch (type) {
	case NUMBER:
	    push(atof(s)); 
	    break; 
	case VAR:
            push(getvar(s[0]));
	    break; 
	case ASSIGN:
	    setvar(s[0], top()); 
	    break; 
	case RECENTPRINT:
	    push(getrecentprint()); 
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
	case '%':
	    op2 = pop(); 
	    if (op2 != 0.0)
		push((int)pop() % (int)op2); 
	    else
		printf("error:zero divisor in modulus calculation\n"); 
	    break; 
	case SIN:
	    push(sin(pop())); 
	    break; 
	case EXP:
	    push(exp(pop())); 
	    break; 
	case POW:
	    op2 = pop(); 
	    push(pow(pop(), op2)); 
	    break; 
	case TOP:
	    op2 = top(); 
	    setrecentprint(op2); 
	    printf("Top: \t%.8g\n", op2); 
	    break; 
	case DUPLICATE:
	    duplicate(); 
	    break; 
	case SWAPTOP:
	    swaptop(); 
	    break; 
	case CLEAR:
	    clear(); 
	    break; 
	case '\n':
	    op2 = top(); 
	    setrecentprint(op2); 
	    printf("\t%.8g\n", pop()); 
	    break; 
	default:
	    printf("error: unknown command %s\n", s); 
	} 
    }
    return 0; 
}

/*********************************************************************/
/* push and pop */ 
#define MAXVAL 100  /* maximum depth of val stack */ 

int sp = 0;         /* next free stack position */ 
double val[MAXVAL]; /* value stack */ 

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

/* function to debug the stack */
void printstack()
{
    printf("Current stack:\t"); 
    for (int i = 0; i < sp; i++)
	printf("%f\t", val[i]); 
    printf("\n"); 
}

/* top: return the top of the stack */
double top(void)
{
    double f = pop(); /* make sure error check is performed */
    push(f); 
    return f; 
}

/* duplicate: duplicate the top element of the stack */
void duplicate(void)
{
    double f = top(); 
    push(f); 
}

/* swaptop: swap the top two elements of the stack */
void swaptop(void)
{
    double f = pop(); 
    double g = pop(); 
    push(f); 
    push(g); 
}

/* clear: clear the stack */
void clear(void)
{
    sp = 0; 
}

/*********************************************************************/


/*********************************************************************/
/* getop: get next operator or numeric operand */
#include <ctype.h>
#include <string.h>
#define MATCH    1
#define NO_MATCH 0

int getch(void); 
void ungetch(int); 
void ungets(char[]); /* Exercisr 4-7 */
int match(char[]); 

/* Exercise 4-3, added provision for negative numbers */
int getop(char s[])
{
    int i, c;    

    while ((s[0] = c = getch()) == ' ' || c == '\t')
	; 

    /* recognizing math functions */
    if (c == 'S' && match(PSIN)) 
	return SIN; 
    if (c == 'E' && match(PEXP))
	return EXP; 
    if (c == 'P' && match(PPOW))
	return POW; 

    if (c == 'R' && match(RECP))
	return RECENTPRINT; 
    
    s[1] = '\0'; 

    /* recognizing single letter variables */
    if (isalpha(c) && islower(c)) {
	if (match(ASSN))
	    return ASSIGN; 
	else
	    return VAR; 
    }

    if (!isdigit(c) && c != '.' && c != '-')
	return c; /* not a number */
    
    if (c == '-') {
	if (!isdigit(c = getch())) {  /* if the '-' is minus */
	    ungetch(c);  
	    return '-'; 
	} else                        /* if the '-' is the negative sign */
	    ungetch(c);
    }

    i = 0; 
    if (isdigit(c)) /* collect integer part */
	while (isdigit(s[++i] = c = getch()))
	    ;
    if (c == '.')
	while (isdigit(s[++i] = c = getch())) /* collect the fraction part */
	    ; 
    s[i] = '\0'; 

    if (c != EOF)
	ungetch(c); 
    return NUMBER; 
}

/* match(p): match the given string pattern p from the input
   returns 1 if the pattern specified is matched, 0 if not matched. 
   If the pattern is matched, the input pointer is moved to the character
   right after the matched pattern, otherwise the input pointer is reset 
   to the value before this function is called. This behaviour is implemented
   by calling ungets to push the unmatched pattern back into the buffer. 
 */ 
int match(char p[])
{
    char t[MAXOP]; 
    int i; 
    int state = MATCH; 
    for (i = 0; p[i] != '\0' && state; i++) {
	t[i] = getch(); 
	if (t[i] != p[i]) {
	    state = NO_MATCH;
	}
    }

    t[i] = '\0';

    if (state == NO_MATCH) {
	ungets(t); 
    }

    return state; 
}

/*********************************************************************/

/*********************************************************************/
/* getch and ungetch */
#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
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

/* Exercise 4-7 */
/* ungets(s): put an entire string back into the buffer */
void ungets(char s[])
{
    for (int i = strlen(s) - 1; i >= 0; i--) { 
	ungetch(s[i]); 
    }
}

/* function to debug the buf */
void printbuf()
{
    printf("Current buf:\t"); 
    for (int i = 0; i < bufp; i++)
	printf("%c\t", buf[i]); 
    printf("\n"); 
}

/*********************************************************************/

/*********************************************************************/
/* table for variables */
#define MAXVAR 27   /* all the letters plus the most recently printed */
double sym[MAXVAR]; 

void setvar(char var, double f)
{
    sym[var - 'a'] = f;  
}

void setrecentprint(double f)
{
    sym[MAXVAR - 1] = f; 
}

double getvar(char var)
{
    return sym[var - 'a']; 
}

double getrecentprint()
{
    return sym[MAXVAR - 1]; 
}

/*********************************************************************/
