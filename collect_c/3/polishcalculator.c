#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE     100     /* size of character input buffer */
#define MAXVAL      100     /* maximum depth of val stack */
#define MAXOP       100     /* max size of operand or operator */
#define NUMVARS     26      /* number of variables */
#define NUMBER      '0'     /* signal that a number was found */
#define COMMAND     '1'     /* signal that a function command was found */
#define OPERATOR    '2'     /* signal that an operator was found */
#define VARIABLE    '3'     /* signal that a variable was encountered */
#define NEWLINE     '4'     /* signal that a newline was encountered */

int sp = 0;                 /* next free stack position */
int bufp = 0;               /* next free position in buf */
double val[MAXVAL];         /* value stack */
char buf[BUFSIZE];          /* buffer for ungetch */
double vars[NUMVARS];       /* array for variables */

int getop(char []);
void push(double);
double pop(void);
double top(void);
void duplicate(void);
void swap(void);
void clear(void);
void funceval(char []);
void opeval(char);
void vareval(char);
int getch(void);
void ungetch(int);

/* reverse Polish calculator */
main() 
{
    int type, i;
    char s[MAXOP];

    for (i = 0; i < NUMVARS; i++)   
        vars[i] = 0.0;  /* initialize variables array */

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case COMMAND:
            funceval(s);
            break;
        case OPERATOR:
            opeval(s[0]);
            break;
        case VARIABLE:
            vareval(s[0]);
            break;
        case NEWLINE:
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    return 0;
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

/* top: return top value from stack without popping */
double top(void)
{
    return val[sp];
}

/* duplicate: duplicate the top stack value */
void duplicate(void) 
{
    if (sp < MAXVAL) {
        val[sp + 1] = val[sp];
        sp++;
    } else
        printf("error: stack full, can't duplicate\n");
}

/* swap: swap the top two values on the stack */
void swap(void) 
{
    if (sp >= 1) {
        int temp;
        temp = val[sp];
        val[sp] = val[sp-1];
        val[sp-1] = temp;
    } else
        printf("error: stack contains less than two values, can't swap\n");
}

/* clear: clear all values from the stack */
void clear(void) 
{
    val[sp] = 0.0;
    while (sp > 0)
        val[--sp] = 0.0;
}

/* funceval: evaluate user entry stored in s */
void funceval(char s[]) 
{
    int op1, op2, c;

    if (strcmp(s, "top") == 0) {
        c = getch();
        printf("\t%.8g\n", top());
    } else if (strcmp(s, "duplicate") == 0) {
        c = getch();
        duplicate();
    } else if (strcmp(s, "swap") == 0) {
        c = getch();
        swap();
    } else if (strcmp(s, "clear") == 0) {
        c = getch();
        clear();
    } else if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "tan") == 0)
        push(tan(pop()));
    else if (strcmp(s, "asin") == 0)
        push(asin(pop()));
    else if (strcmp(s, "acos") == 0)
        push(acos(pop()));
    else if (strcmp(s, "atan") == 0)
        push(atan(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        op1 = pop();
        if (op1 == 0.0 && op2 <= 0.0) {
            printf("error: domain error\n");
            push(0.0);
        }
        else if (op1 < 0.0)
            push(pow(op1, (int)op2));
        else
            push(pow(op1, op2));
    } else
        printf("error: invalid command\n");
}

/* opeval: evaluate user entry stored in s, return result */
void opeval(char operator) 
{
    double operand;

    switch (operator) {
    case '+':
        push(pop() + pop());
        break;
    case '*':
        push(pop() * pop());
        break;
    case '-':
        operand = pop();
        push(pop() - operand);
        break;
    case '/':
        operand = pop();
        if (operand != 0.0)
            push(pop() / operand);
        else
            printf("error: zero divisor\n");
        break;
    case '%':
        operand = pop();
        push((int) pop() % (int) operand);
        break;
    default:
        printf("error: unknown operator %c\n", operator);
        break;
    }
}

/* vareval: evaluate variable passed as argument */
void vareval(char var) 
{
    int pos = var - 97;
    if (vars[pos] == 0.0) {
        vars[pos] = top();
        pop();
    } else
        push(vars[pos]);
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i = 0, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (c == '\n')
        return NEWLINE;
    if (c == '-') { /* test for negative number */
        if (isdigit(c = getch())) { /* negative number input */
            s[0] = '-';
            s[++i] = c;
        } else {    /* minus operator input, put back on buffer */
            ungetch(c);
            return OPERATOR;
        }
    }   /* function command/variable in input */
    if (isalpha(c)) {
        s[0] = tolower(s[0]);
        while (isalpha(s[++i] = c = tolower(getch())))
            ;
        if (i == 1)
            return VARIABLE;
        s[i+1] = '\0';
        ungetch(c);
        return COMMAND;
    }
    if (!isdigit(c) && c != '.')
        return OPERATOR;
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

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

