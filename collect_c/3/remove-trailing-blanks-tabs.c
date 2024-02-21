#include<stdio.h>
#define MAXLINE 1000 

int getline_(char line[], int maxline);
int remove_(char s[]);

/*exercise 1-18
 *
 * only removes trailing blacks and tabs
 *
 * */

int main(){
    char line[MAXLINE];
    while (getline_(line, MAXLINE) > 0)
        if (remove_(line) > 0)
            printf("%s", line);
    return 0;
}

int remove_(char s[]){
    int i;
    i = 0;
    while (s[i] != '\n')
        i++;
    i--;
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
        i--;
    if (i >= 0){
        i++;
        s[i] = '\n';
        i++;
        s[i] = '\0';
    }
    return i;

}

int getline_(char s[], int lim){
    int c, i, j;
    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
        if (i < lim -2){
            s[j] = c;
            j++;
        }
    if (c == '\n'){
        s[j] = c;
        j++;
        i++;
    }
    s[i] = '\0';
    return i;
}
