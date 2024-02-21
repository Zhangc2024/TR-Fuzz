#include <stdio.h>

#define  MAXCOL  85    /* maximum column of input */
#define  TABINC  8     /* tab increment size      */

char word[MAXCOL];     /* iput line               */

int exptab(int pos);

main(){
    int c, pos, i, j ,m;

    pos = 0;
    i = 0;
    j = 0;
    m = 0;

    while ((c = getchar()) != EOF ){
        if (c == ' ' || c == '\t' || c == '\n'){
            for( j = 0; j < i ; j++ )
                putchar(word[j]);
            if (m == 1)
                pos = i + 1;

            i = 0;
            m = 0;

            if (c == '\t')
                pos = exptab(pos);
            if (c == ' '){
                ++pos;
                if (pos > MAXCOL){
                    putchar('\n');
                    pos = 1;
                }
                putchar(' ');
            }
            if (c == '\n'){
                putchar('\n');
                pos = 0;
            }
        } else {
            word[i] = c;
            ++pos;
            ++i;
            if ( pos >= MAXCOL && i < MAXCOL ){
                putchar('\n');
                pos = 0;
                m = 1;
            }
        }
    }
    for( j = 0; j < i ; j++ )
        putchar(word[j]);
}
int exptab(pos){
    int i;
    i = 0;

    ++pos;
    ++i;
    while (pos % TABINC != 0){
        ++pos;
        ++i;
    }

    if (pos > MAXCOL){
        putchar('\n');
        while (i > 0){
            putchar(' ');
            --i;
        }
        return i;
    }else{
        while (i > 0){
            putchar(' ');
            --i;
        }
        return pos;
    }
}


