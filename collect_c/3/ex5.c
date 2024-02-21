#include <stdio.h>

/* 1.5.2 This program counts character in input : 2nd version */

int main()
{  
    double nc;

    for(nc = 0; getchar() != EOF; ++nc)
        ;

    printf("The number of character including (\\n) is %.0f\n", nc);
    
    return 0;
}
