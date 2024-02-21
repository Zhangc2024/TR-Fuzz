#include <stdio.h>

/*If you're typing at the terminal and you want to provoke
an end-of-file, use CTRL-D (unix-style systems) or CTRL-Z (Windows).*/

int main(){

    int c;

    while(c = (getchar() != EOF))
        printf("%d\n", c);
    printf("%d reaching the End Of File\n", c);
}
