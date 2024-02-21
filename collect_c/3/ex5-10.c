/*
 * Exercise 5-10.
 *
 * Write the program expr, which evaluates a revere Polish expression
 * from the command line, where each operator or operand is a separate
 * argument. For example, on the command line enter
 *
 * ./a.out 2 3 4 + \*
 *
 * evaluates 2 X (3 + 4)
 *
 * based on C answer book
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include <ctype.h>


#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define NAME 'n' /* signal that a name was found */

int getop(char []);
int getch(void);
void ungetch(int);
void ungets(char []);
void push(double);
double pop(void);

#define MAXVAL 100  /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */


/* reverse Polish calculator; uses command line */

int main(int argc, char *argv[])
{
    char s[MAXOP];
    double op2;

    while (--argc > 0)
    {
        ungets(" "); /* push end of argument */
        ungets(*++argv);    /* push an argument */

        switch(getop(s)) {

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
        default:
            printf("error: unknown command %s\n", s);
            argc = 1; // to get out of while loop in next iteration
            break;
        }
    }

    printf("\t%.8g\n", pop());

    return 0; //return SUCCESS
}


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

/* getop: get next operator, numberic operand, or math fnc */
int getop(char s[])
{
    int c, i;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';
    i = 0;

    if (islower(c)) /* command or NAME */
    {
        while(islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';

        if (c != EOF)
            ungetch(c); /* went one char too far */

        if (strlen(s) > 1)
            return NAME;    /* > 1 char; it is NAME */
        else {
            return s[0];       /* it may be a command */
        }
    }

    if (!isdigit(c) && c != '.')
        return c;   /* not a number */
    
    if (isdigit(c))
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

void ungets(char s[])
{
    int len = strlen(s);

    while (len > 0)
        ungetch(s[--len]);
}
