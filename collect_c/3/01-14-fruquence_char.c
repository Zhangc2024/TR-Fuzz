#include <stdio.h>

main()
{
    int i,c,ndigit[26],max,j;

    for (i = 0; i < 26; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
    if (c >= 'a' && c <= 'z'){
        ++ndigit[c-'a'];
    }else if( c >= 'A' && c <= 'Z') {
        ++ndigit[c-'A'];
    }

    for(i = 0; i < 26; ++i){
        putchar(97+i);
        printf(":%d ",ndigit[i]);
    }

    printf("\n");

    max = ndigit[0];

    for (i = 0; i < 26; ++i){
        if (ndigit[i] > max)
            max = ndigit[i];
    }

    for (i = max; i > 0; i = i-10){
        for (j = 0; j < 26; ++j){
            if (ndigit[j] >= i)
                printf("* ");
            else
                printf("  ");
        }
        putchar('\n');
    }

    for(i = 0; i < 26; ++i){
        putchar(97+i);
        putchar(' ');
        //printf(":%d ",ndigit[i]);
    }
}
