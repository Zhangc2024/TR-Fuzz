// check whether an alphabet is vowel or constant

#include <stdio.h>

int main()
{
    char alphabet;
    int lowercase, uppercase;

    printf("Please enter an alphabet: ");
    scanf("%c", &alphabet);

    lowercase = (alphabet == 'a' || alphabet == 'e' || alphabet == 'i' || alphabet == 'o' || alphabet == 'u');
    uppercase = (alphabet == 'A' || alphabet == 'E' || alphabet == 'I' || alphabet == 'O' || alphabet == 'U');

    if (lowercase || uppercase)
    {
        printf("%c is a vowel.\n", alphabet);
    }
    else
    {
        printf("%c is a consonant.\n", alphabet);
    }

    return 0;
}