#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define NEGATIVE_NUMBER '1' /* signal that a signed number was found */

/*
 *  
 *  Exercise 4-3. Given the basic framework its straightforward to extend the calculator.
 *  Add the modulus (%) operator and provisions for negative numbers.
 *
 */

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    /*printf("The negative # of -10 is %f\n", atof("-10"));*/

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
                printf("\t%.8g\n", pop());
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

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
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





