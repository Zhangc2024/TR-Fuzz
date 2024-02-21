#include<stdio.h>
#define MAX 1000

void rev(void);

char s[MAX];
char reversed[MAX];
int len;

/* exercise 1-19 */

int main(){
    int c;
    extern int len;
    len = 0;
    while ((c = getchar()) != EOF){
        s[len] = c;
        len++;
    }
    rev();
    return 0;
}
void rev(void){
    extern char s[];
    extern char reversed[];
    int rcount = 0;
    for(int i = len -1 ; i >= 0; i--){
        reversed[rcount] = s[i];
        rcount++;
    }
    reversed[rcount + 1] = '\0';
    printf("%s\n", reversed);
}
