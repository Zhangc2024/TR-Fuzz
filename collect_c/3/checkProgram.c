#include <stdio.h>

main()
{
    int c, parentheses = 0, brackets = 0, braces = 0,
        flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
    
    /* process input and increment counters */
    while ((c = getchar()) != EOF) {
       /* single quote encountered */
       if ((c == '\'') && flag2 != 1) {
           if (flag3 != 1) flag3 = 1;
           else flag3 = 0;
       } /* double quote encountered */
       else if ((c == '\"') && flag2 != 1) {
           if (flag4 != 1) flag4 = 1;
           else flag4 = 0;
       } /* possible beginning of comment */
       else if (c == '/' && flag3 != 1 && flag4 != 1) {  
           flag1 = 1; 
           c = getchar();
           if (c == '*') flag2 = 1;
           else if (flag2 != 1) {   /* not beginning of comment */
               flag1 = 0;
           }
       }    /* comment already in process */
       else if (flag2 == 1 && flag3 != 1 && flag4 != 1) {
           if (c == '*') {
               flag1 = 0;
               c = getchar();
               if (c == '/') flag2 = 0;
               else { /* not end of comment */ 
                   flag1 = 1;
               }
           }
       }  /* comment not encountered */
       else {
            switch(c) {
                case '(':
                    ++parentheses;
                    break;
                case ')':
                    --parentheses;
                    break;
                case '{':
                    ++brackets;
                    break;
                case '}':
                    --brackets;
                    break;
                case '[':
                    ++braces;
                    break;
                case ']':
                    --braces;
                    break;
            }
       }
    }

    if (parentheses != 0) printf("Parentheses error.\n");
    else if (brackets != 0) printf("Brackets error.\n");
    else if (braces != 0) printf("Braces error.\n");
    else printf("No errors encountered.\n");

    return 0;
}
