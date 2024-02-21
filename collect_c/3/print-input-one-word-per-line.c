#include<stdio.h>

int main(){
    int c;
    while((c = getchar()) != EOF){
        putchar(c);
        if (c == ' '){
            printf("\n");
        }
    }
    return 0;
}
