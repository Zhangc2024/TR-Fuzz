#include <stdio.h>
#define MAXLIMIT 1000

main(){
    enum loop {NO, YES};
    enum loop okloop = YES;

    int i, lim, c;
    char s[MAXLIMIT];
    i = 0;

    while(okloop == YES)
    {
        if (i >= lim-1)     /* outside of valid range ?*/
            okloop = NO;
        else if ((c = getchar()) == '\n')
            okloop = NO;
        else if (c == EOF)  /* end of file */
            okloop = NO;
        else {
            s[i] = c;
            ++i;
        }
    }
}
