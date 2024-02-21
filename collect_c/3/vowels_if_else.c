// progrmam to input a character and print if it is a vowel or not.

// vowel : a,e,i,o  u

#include <stdio.h>
int main()
{
    char ch;

    printf("Please input a character : ");
    scanf("%c", &ch);

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        printf("It is a vowel.");
    else
        printf("It is a consonent.");

    return 0;
}