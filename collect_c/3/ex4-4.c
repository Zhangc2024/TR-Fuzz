#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define NEGATIVE_NUMBER '1' /* signal that a signed number was found */
#define PEEK '2'
#define DUPLICATE '3'
#define SWAP '4'
#define CLEAR '5'
#define POP '6'

/*
 *  
 *  Exercise 4-4. Add commands: 
 *  a) print top element of the stack without popping it
 *  b) duplicate the top element of the stack and push the duplicated value to the top
 *  c) swap the top two elements
 *  d) clear the stack
 *
 */

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
double peek(void);
void dup(void);
void swap(void);
void clear(void);

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case NEGATIVE_NUMBER:
                push(-1 * atof(s));
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
                push((int)pop() % (int)op2);
                break;
            case '\n':
                //do nothing
                break;
            case POP:
                printf("\t%.8g\n", pop());
                break;
            case PEEK:
                printf("\t%.8g\n", peek());
                break;
            case DUPLICATE:
                dup();
                break;
            case SWAP:
                swap();
                break;
            case CLEAR:
                clear();
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;  
        }
    }

    return 0; //return SUCCESS
}

#define MAXVAL 100  /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL) {  
        val[sp++] = f;
    } else {
        printf ("error: stack full, can't push %g\n", f);
    }
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0) {
        return val[--sp];
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* peek: return top element without popping */
double peek(void)
{
    printf("sp is %d\n", sp);
            
    if (sp > 0) {
        return val[sp - 1];
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* dup : duplicate top element and push it in the stack */
void dup(void)
{
    push(peek());
}

/* swap: swap top two elements */
void swap(void)
{
    double first;
    double second;

    if (sp > 0) {

        first  = pop();

        if (sp > 0) {

            second = pop();

            push(first); 
            push(second);

        }
    }
}

/* clear: clear the stack */
void clear(void)
{
    while(sp > 0) {
        pop();
    }
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!isdigit(c) && c != '.' && 
            c != '-' && c != 'p' && c != 'd' && c != 's' && c != 'c' && c != 'r')
        return c; /* not a number */

    i = 0;

    int is_neg = 0;

    if (c == '-') {
               
        is_neg = 1;

        s[0] = c = getch();

        if (!isdigit(c) && c != '.') // check if '-' is an operator or a sign
        {  
            // '-' is a operator
            ungetch(c);
            return '-'; 
        }          
    }

    switch(c) {
    case 'p':
        return PEEK;
    case 'd':
        return DUPLICATE;
    case 's':
        return SWAP;
    case 'c':
        return CLEAR;
    case 'r':
        return POP;
    default:
        break;
    }

    if (isdigit(c)) { /* collect integer part */
        
        while (isdigit(s[++i] = c = getch()))
                ;
    }
    
    if (c == '.') { /* collect fraction part */
        
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    

    s[i] = '\0';

    if (c != EOF) {
        ungetch(c);
    }

    return (is_neg ? NEGATIVE_NUMBER : NUMBER);
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0 ) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}





