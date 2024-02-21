//Program to reverse the string.

#include<stdio.h>
#include<conio.h>
#include<string.h>

char *strrev(char *str)
{
    char *p1, *p2;

    if (!str || !*str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

void main()
{
    char arr[100];

    printf("\nEnter a string to reverse : ");
    gets(arr);

    strrev(arr);

    printf("\nReverse of entered string is : %s", arr);

    getch();
}

/*Program to reverse the string using pointer.

#include<stdio.h>
#include<conio.h>

void main()
{
    char str_array[10000], *ptr;
    int i, len;
    clrscr();

    printf("Enter a string : ");
    gets(str_array);
    ptr = str_array;

    for (i = 0; i < 10000; i++)
    {
        if (*ptr == '\0')
            break;
        ptr++;
    }

    len = i;
    ptr--;
    printf("\nReversed String is : ");
    for (i = len; i > 0; i--)
    {
        printf("%c", *ptr--);
    }
    getch();
}*/
