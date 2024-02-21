# include <stdio.h>
# define MAXLINE 1000                   /* maximum input line size */

int mygetline(char line[], int maxline);
int myremove(char s[]);

/* remove trailing blanks and tabs, and delete blank lines */
int main(){
    int len;                            /* current line length */
    char line[MAXLINE];                 /* current input line */

    while(mygetline(line, MAXLINE) > 0){
        if(myremove(line) > 0) {
            printf("Input: %s\n", line);
        }
    }
    return 0;
}
/* remove trailing blanks and tabs from character string s */
int myremove (char s[]) {
    int i = 0;
    while (s[i] != '\n') {
        ++i;
    }
    /* back off from '\n' */
    --i;
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t')) {
        --i;
    }
    if (i >= 0) {           /* check if this is a nonblank line */
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }
    return i;
}

/* mygetline: read a line into s, return length */
int mygetline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim-1 &&(c = getchar()) != EOF &&c != '\n'; ++i){
        s[i] = c;
    }
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
