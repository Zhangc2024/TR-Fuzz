// check if the number is a palindrome

#include <stdio.h>

int main()
{
    int n, reverseN = 0, remainder, originalN;

    printf("Enter an integer: ");
    scanf("%d", &n);
    originalN = n;

    while (n != 0)
    {
        remainder = n % 10;
        reverseN = reverseN * 10 + remainder;
        n /= 10;
    }

    if (originalN == reverseN)
    {
        printf("%d is a palindrome.\n", originalN);
    }
    else
    {
        printf("%d is not a palindrome.\n", originalN);
    }

    return 0;
}