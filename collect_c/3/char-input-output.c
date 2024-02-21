#include <stdio.h>

int main()
{
    char c;

    printf("Please input a character : \n");
    // puts("Please input a character : ");

    // scanf("%c", &c);
    // c = getchar();
    c = getc(stdin);

    puts("You have inputted. ");

    //printf("%c", c);
    // putchar(c);
    putc(c, stdout);
}
