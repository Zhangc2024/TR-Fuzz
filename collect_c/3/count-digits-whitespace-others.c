#include<stdio.h>

int main(){
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;

    for(i = 0; i < 10; i++)
        ndigit[i] = 0;

    while((c = getchar()) != EOF)
        if (c >= '0' && c <= '9'){
            /* if you type a number between 0-9 i.e the chars '0'-'9'
             * C language can convert them to ints simply by
             * appending -'0'
             * eg '1' becomes the integer 1 if we '1'-'0'
             * '2' becomes the integer 2 if we '2'-'0'
             */
            ++ndigit[c-'0'];
            /*
            * remember ++i represents i = i + 1
            * therefore ++arrayName[i] is arrayName[i] = arrayName[i] + 1
            */
        }
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    printf("digits = ");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
    return 0;
}
