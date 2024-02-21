#include <stdio.h>

#define in  1  /* inside a word */
#define out 0  /* outside a word */

/* count lines, words, and characters in input */

main()
{
   int c, nl, nw, nc, state;
   
   state = out;
   nl = nw = nc = 0;
   while ((c = getchar()) != EOF) {
       ++nl;
       if (c == ' ' || c == '\n' || c == '\t')
           state = out;
        else if (state == out) {
            state = in;
            ++nw;
        }
   }
   printf("%d %d %d\n", nl, nw, nc);
}

