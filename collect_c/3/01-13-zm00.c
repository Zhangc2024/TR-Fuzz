#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
    int c,i,j,state,n,max;
    int ndigit[11];

    for (i = 0; i <= 10; ++i)
        ndigit[i]=0;

    n = 0;

    while ((c = getchar()) != EOF)
        if (c == '\t' || c == '\n' || c == ' '){
            if (state =  IN){
                state = OUT;
                if (n >= 1 && n <= 10)
                    ++ndigit[n];
                n = 0;
            }
        }else{
            ++n;
            if (state = OUT)
                state = IN;
        }

    max = ndigit[1];

    for (i = 1; i <= 10; ++i){
        if (ndigit[i] > max)
            max = ndigit[i];
    }

    for (i = max; i > 0; --i){
        for (j = 1; j <= 10; ++j){
            if (ndigit[j] >= i)
                printf("* ");
            else
                printf("  ");
        }
        putchar('\n');
    }
    printf("--------------------\n");
    printf("1 2 3 4 5 6 7 8 9 10");
}
