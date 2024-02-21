// progrmam to input a character and print if it is a vowel or not.

// vowel : a,e,i,o  u

#include <stdio.h>
int main()
{
    char ch;

    printf("Please input a character : ");
    scanf("%c", &ch);

    switch (ch)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        printf("It is a vowel.");
        break;
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        printf("It is an uppercase vowel.");
        break;

    default:
        printf("It is a consonent.");
    }

    return 0;
}
