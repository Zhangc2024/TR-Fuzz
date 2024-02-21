#include <stdio.h>
#include <string.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include <ctype.h>

/*
 * Exercise 4.11 Modify getop so that it doesn't need to use ungetch.
 * Hint: use an internal static variable.
 * From C solutions book.
 */

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define NAME 'n' /* signal that a name was found */

int getop(char []);
void push(double);
double pop(void);


/* reverse Polish calculator */
int main()
{
    int i, type, var = 0;
    double op2, v;
    char s[MAXOP];
    double variable[26];

    for (i = 0; i < 26; i++)
    {
        variable[i] = 0.0;
    }
    
    while ((type = getop(s)) != EOF)
    {
       switch(type) {
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
            case '=':
                pop();
                if (var >= 'A' && var <= 'Z')
                    variable[var - 'A'] = pop();
                else
                    printf("Error: no variable name\n");
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
                    printf("Error: unknown command %s\n", s);
                break;
        }
        var = type;
    }

    return 0; //return SUCCESS
}

int getch(void);
//void ungetch(int);

/* getop: get next operator, numberic operand, or math fnc */
int getop(char s[])
{
    int c, i;
    static int lastc = 0;

    if (lastc == 0)
        c = getch();
    else {
        c = lastc;
        lastc = 0;
    }

   while ((s[0] = c) == ' ' || c == '\t')
       c = getch();
   s[1] = '\0';
   if (!isdigit(c) && c != '.')
       return c; /* not a number */

   i = 0;
   if (isdigit(c))  /* collect integer part */
       while (isdigit(s[++i] = c = getch()))
        ;
   if (c == '.')    /* collect fraction part */
       while (isdigit(s[++i] = c = getch()))
        ;

   s[i] = '\0';
   if (c != EOF)
       lastc = c;

   return NUMBER;
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

char buf = 0; /* buffer for ungetch */

int getch(void) /* get a (possibly pushed back) character */
{
    int c;

    if (buf != 0) {
        c = buf;
    } else {
        c = getchar();
    }

    buf = 0;

    return c;
}

/* push character back on input */
/**void ungetch(int c) 
{
    if (buf != 0) {
        printf("ungetch: too many characters\n");
    } else {
        buf = c;
    }
}*/
