# include <stdio.h>
# define TABINC 8
int main() {
    int c, pad, pos;
    pos = 0;
    pad = 0;
    while((c = getchar()) != EOF){
        if(c == '\t'){
            pad = TABINC - pos % TABINC;
            while(pad > 0){
                putchar(' ');
                ++pos;
                --pad;
            }
        }
        else if(c == '\n'){
            putchar(c);
            pos = 0;
        }
        else{
            putchar(c);
            ++pos;
        }
    }
}
