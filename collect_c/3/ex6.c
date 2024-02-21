#include <stdio.h>

/* 1.5.3 Line Counting */

int main()
{
    
    int c, nl;

    nl = 0;

    while((c = getchar()) != EOF) 
    {
        if(c == '\n')
            ++nl;
    }

    printf("%d\n", nl);

    return 0; //return SUCCESS
}
