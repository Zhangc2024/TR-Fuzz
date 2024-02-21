# include <stdio.h>
# define MAXLINE 1000                   /* maximum input line size */

int mygetline(char line[], int maxline);

int main(){
    int len;                            /* current line length */
    int max;                            /* maximum length seen so far */
    char line[MAXLINE];                 /* current input line */

    max = 0;
    while((len = mygetline(line, MAXLINE)) > 0){
        if(len > 20) {
            printf("Length: %d, input: %s\n", len, line);
        }
    }
    return 0;
}
/* mygetline: read a line into s, return length */
int mygetline(char s[], int lim){
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
