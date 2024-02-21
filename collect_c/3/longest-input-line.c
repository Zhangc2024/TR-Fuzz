#include<stdio.h>
#define MAXLINE 1000

/* getline is already defined in stdio.h
 * to avoid conflicting declarations, we use getline_
 */

char line[MAXLINE];
char longest[MAXLINE];
int max;

int getline_(void);
void copy(void);

int main(){
    int len;
    /* since variables are declared in this file,
     * extern is not nescessary
     * it is implicit
     *
     * extern char longest[];
     *
     */

    max = 0;
    while ((len = getline_()) > 0)
        if (len > max){
            max = len;
            copy();
        }
    if (max > 0)
        printf("the longest is - %s", longest);
    return 0;
}

int getline_(void){
    int c, i;
    for (i = 0; i < MAXLINE -1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    if (c == '\n'){
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}

void copy(void){
    int i;
    i = 0;
    while((longest[i] = line[i]) != '\0')
        i++;
}
