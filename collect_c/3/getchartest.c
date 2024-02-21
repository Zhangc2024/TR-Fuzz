#include <stdio.h>

/* program to test the value of getchar() != EOF */
main()
{
    int c;
    
    while ((c = getchar()) != EOF)
        printf("%d", getchar() != EOF);
}
