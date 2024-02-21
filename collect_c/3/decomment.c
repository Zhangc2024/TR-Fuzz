#include <stdio.h>

main()
{
    int c, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;

    /* continually process input */
    while ((c = getchar()) != EOF) {
       /* single quote encountered */
       if ((c == '\'') && flag2 != 1) {
           if (flag3 != 1) flag3 = 1;
           else flag3 = 0;
           putchar(c);
       } /* double quote encountered */
       else if ((c == '\"') && flag2 != 1) {
           if (flag4 != 1) flag4 = 1;
           else flag4 = 0;
           putchar(c);
       } /* possible beginning of comment */
       else if (c == '/' && flag3 != 1 && flag4 != 1) {  
           flag1 = 1; 
           c = getchar();
           if (c == '*') flag2 = 1;
           else if (flag2 != 1) {   /* not beginning of comment */
               putchar('/');
               putchar(c);
               flag1 = 0;
           }
       }    /* comment already in process */
       else if (flag2 == 1 && flag3 != 1 && flag4 != 1) {
           if (c == '*') {
               flag1 = 0;
               c = getchar();
               if (c == '/') flag2 = 0;
               else { /* not end of comment */ 
                   putchar('*');
                   putchar(c);
                   flag1 = 1;
               }
           }
       }  /* comment not encountered */
       else putchar(c);
    }

    return 0;
}
