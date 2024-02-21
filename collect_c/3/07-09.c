#include <stdio.h>
#define isupper3(c)  ((c) >= 'A' && (c) <= 'Z' ) ? 1 : 0
main()
{
    int isupper2(char c);
    printf( "a is upper? : %d\n", isupper2('a') );
    printf( "C is upper? : %d", isupper3('C') );
}

/* isupper: return 1 (true) if c is an upper case letter */
int isupper2(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}
