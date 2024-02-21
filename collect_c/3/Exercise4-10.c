#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXLINE 100
#define MAXVAL 100 

int li= 0;  
char line[MAXLINE];
int sp = 0;
double val[MAXVAL];

int getline(char line[],int limit);
int getop(char []);
void push(double);
double pop(void);

main() {
	
    int type;
    double op2;
    char s[MAXOP];
    
    while((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER: push(atof(s)); break;
            case '+': push(pop() + pop()); break;
            case '*': push(pop() * pop()); break;
            case '-': op2 = pop(); push(pop() - op2); break;
            case '/': op2 = pop(); if (op2 != 0.0)
                        push(pop()/op2); break;
            case '\n': printf("      =\t%.9g\n",pop()); break;
            default: printf("error: unknown command %s\n",s); break;
        }
    }
    return 0;
}

void push(double f) {
	
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full,can't push %g\n",f);
}

double pop(void) {
	
    if(sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty \n");
        return 0.0;
    }
}  

int getop(char s[]) {
	
    int c, i;

    if(line[li] == '\0')
        if(getline(line,MAXLINE) == 0)
            return EOF;
        else
            li =0;
    
    while((s[0] = c = line[li++]) == ' ' || c == '\t');
    s[1] = '\0';
    
    if(!isdigit(c) && c!= '.')
        return c;
    
    i = 0;
    
    if(isdigit(c))
        while(isdigit(s[++i] = c = line[li++]))
            ;
    if( c == '.')
        while(isdigit(s[++i] = c = line[li++]))
            ;
    
    s[i] = '\0';

    li--;

    return NUMBER;
}

int getline(char s[],int lim) {
	
    int i, c;

    for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
        s[i] =c;
    
    if(c=='\n')
        s[i++] =c;

    s[i]='\0';
    
    return i;
}

