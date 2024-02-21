#include <stdio.h>

void rcomment(int c);
void in_comment(void);
void line_comment(void);
void echo_quote(int c);

/* the answer book don't consider the double slash comment */
/* remove all comments from a valid C program */

main()
{
    int c,d;

    while((c = getchar()) != EOF)
        rcomment(c);
    return 0;
}

/* rcomment: read each character, remove the comments */
void rcomment(int c)
{
    int d;

    if ( c == '/')
        if ((d = getchar()) == '*')
            in_comment();       /* beginning comment */
        else if (d == '/'){
            line_comment();     /* line comment */
        } else {
            putchar(c);         /* not a comment */
            putchar(d);
        }
    else if ( c == '\'' || c == '"')
        echo_quote(c);          /* quote begins */
    else
        putchar(c);             /* not a comment */
}

void line_comment(void){
    int c;
    while ( (c = getchar()) != '\n')
        ;
}

/* in_comment: inside of a valid comment */
void in_comment(void)
{
    int c, d;

    c = getchar();                  /* prev character */
    d = getchar();                  /* current character */
    while (c != '*' || d != '/'){    /* search for end */
        c = d;
        d = getchar();
    }
}

/* echo_quote: echo characters within quotes */
void echo_quote(int c)
{
    int d;

    putchar(c);
    while ((d = getchar()) != c){   /* search for end    */
        putchar(d);
        if (d == '\\')
            putchar(getchar());     /* ignore escape seq */
    }
    putchar(d);
}

