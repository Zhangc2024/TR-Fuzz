#include <stdio.h>

int lower(int c);

main()
{
    char c;

    while ((c = getchar()) != EOF)
        printf("%c", lower(c));

    return 0;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
