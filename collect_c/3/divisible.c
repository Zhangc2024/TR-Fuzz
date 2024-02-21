// to check if a number is divisible by 5 or 7 or not.

#include <stdio.h>

int main()
{

    int no;

    printf("Please input a number : ");
    scanf("%d", &no);

    // divisible by 5 or 7
    if (no % 5 == 0 || no % 7 == 0)
        printf("It is divisible by 5 or 7.");
    else
        printf("It is not divisible by 5 or 7.");

    // not divisible by 5 and 7
    // if (no%5==0 && no%7==0)
    //     printf("It is divisible by 5 and 7.");
    // else
    //     printf("It is not divisible by 5 and 7.");

    return 0;
}