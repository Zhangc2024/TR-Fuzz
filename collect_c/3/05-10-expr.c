#include <stdio.h>
#include <stdlib.h>  /* for atof() */

#define MAXOP 100    /* max size of operand or operator */
#define NUMBER '0'   /* signal that a number was found */

int getop(char[]);
void push(double);
double pop(void);

/* reverse Polish calculator */
main (int argc, char *argv[])
{
    double op2;
    char s[MAXOP];

    while (--argc > 0) {
    	ungets(" ");
    	ungets(*++argv);
        switch (getop(s)) {
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
            break;
        }
    }
    printf("\t%.8g\n", pop());
    return 0;
}
