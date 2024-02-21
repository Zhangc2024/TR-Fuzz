#include <stdio.h>
#define NONBLANK 'a'
main(){
    int c, lastc;
    lastc = NONBLANK;
    while((c = getchar()) != EOF){
        if(c != ' ')
            putchar(c);
        if(c == ' '){
            if(lastc != ' ')
                putchar(' ');
        }
        lastc = c;
    }
}
