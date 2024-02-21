# include <stdio.h>
# define MAXLINE 1000                   /* maximum input line size */
# define threshold 80
int mygetline(char line[], int maxline);
void reverse (char s[]);             /* can't use remove as function name here, for conflicting with stdio.h*/
int main() {
    int len;                            /* current line length */
    char line[MAXLINE];                 /* current input line */
    while(mygetline(line, MAXLINE) > 0){
        reverse(line);
        printf("%s", line);
    }
    return 0;
}
/* getline: read a line into s, return length */
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

void reverse(char s[]){
    int i, j;
    char temp;
    i = 0;
    while(s[i] != '\0'){
        i++;
    }
    // Back from '\0'
    i--;
    if(s[i] == '\n') {
        // Back from '\n' if there's any
        --i;
    }
    j = 0;
    while (j < i){
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        ++j;
        --i;
    }
}
