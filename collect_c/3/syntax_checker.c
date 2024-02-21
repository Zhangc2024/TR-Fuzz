#include<stdio.h>

int brace, brack, paren;

void in_quote(int c);
void in_comment(void);
void search(int c);

int main(){
    int c;
    extern int brace, brack, paren;
    while((c = getchar()) != EOF){
        if (c == '/'){
            if((c = getchar()) == '*')
                in_comment();
            else
                search(c);
        } else if (c == '\'' || c == '"') 
            in_quote(c);
        else
            search(c);
        if(brace < 0){
            printf("unbalanced braces\n");
            brace = 0;
        }
        else if(brack < 0){
            printf("unbalanced brackets\n");
            brack = 0;
        }
        else if(paren < 0){
            printf("unbalanced parenthesis\n");
            paren = 0;
        }

        if(brace > 0)
            printf("unbalanced braces\n");
        if (brack > 0)
            printf("unbalanced brackets\n");
        if(paren > 0)
            printf("unbalanced parenthesis\n");
    }
    return 0;
}

void search(int c){
    extern int brace, brack, paren;
    if(c == '{')
        ++brace;
    else if (c == '}')
        --brace;
    else if (c == '[')
        ++brack;
    else if (c == ']')
        --brack;
    else if (c == '(')
        ++paren;
    else if (c == ')')
        --paren;
}

void in_comment(void){
    int c, d;
    c = getchar();
    d = getchar();
    while(c != '*' || d != '/'){
        c = d;
        d = getchar();
    }
}

void in_quote(int c){
    int d;

    while((d = getchar()) != c)
        if (d == '\\')
            getchar();
}
