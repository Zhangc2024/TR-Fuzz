#include <stdio.h>
#include <string.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include <ctype.h>

/* Exercise 4-10. An alternate organization uses getline to read an
 * entire input line; this makes getch and ungetch unnecessary. Revise
 * the calculator to use this approach.
 *
 * From C Answer book.
 */

#define MAXOP 100 /* max size of operand or operator */
#define MAXLINE 100 /* maximum chars in a line */
#define NUMBER '0' /* signal that a number was found */
#define NAME 'n' /* signal that a name was found */

int li = 0;     /* input line index */
char line[MAXLINE]; /* one input line */

int getop(char []);
void push(double);
double pop(void);
int _getline(char line[], int limit);

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
void ungetch(int);

/* getop: get next operator, numeric operand */
int getop(char s[])
{
    int c, i;

    if (line[li] == '\0')
    {
        if (_getline(line, MAXLINE) == 0)
            return EOF;
        else
            li = 0;
    }

    while ((s[0] = c = line[li++]) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;

    i = 0;

    if (isdigit(c))
        while (isdigit(s[++i] = c = line[li++]))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = line[li++]))
            ;

    s[i] = '\0';
    li--;

    return NUMBER;
}

int _getline(char line[], int limit)
{
    int c, i;
   
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
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

#define BUFSIZE 100

int buf[BUFSIZE]; /* buffer for ungetch */
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
