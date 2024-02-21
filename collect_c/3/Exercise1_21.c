# include <stdio.h>
# define TABINC 8
main(){
    int c, nb, nt, pos;
    nb = 0;
    nt = 0;
    for(pos = 0; (c = getchar()) != EOF; ++pos){
        if(c == ' '){
            if(pos % TABINC != 0)                   /* Not in the position of tab stop */
                ++nb;
            else{
                nb = 0;
                ++nt;                               /* Every time arriving at the tab stop, we could increase nt and initialize nb to 0*/
            }
        }
        else{
            for( ; nt > 0; --nt)
                putchar('\t');
            if(c =='\t')
                nb = 0;
            else{
                for(; nb > 0; --nb)
                    putchar(' ');
            }
            putchar(c);
            if(c == '\n')
                pos = 0;
            else if(c == '\t')
                pos = pos + (TABINC - pos % TABINC) - 1;
        }
    }
}
