// print uppercase and lowercase letters of english

#include <stdio.h>

int main()
{
    char c;

    printf("Enter u to display uppercase alphabets.\n");
    printf("Enter l to display lowercase alphabets.\n");

    scanf("%c", &c);

    if (c == 'U' || c == 'u')
    {
        for (c = 'A'; c <= 'Z'; c++)
        {
            printf("%c ", c);
        }
    }
    else if (c == 'L' || c == 'l')
    {
        for (c = 'a'; c <= 'z'; c++)
        {
            printf("%c ", c);
        }
    }
    else
    {
        printf("invalid character!");
    }
    printf("\n");

    return 0;
}