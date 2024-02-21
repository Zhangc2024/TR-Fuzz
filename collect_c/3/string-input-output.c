#include <stdio.h>

int main()
{
    char name[20] = "Guru Nanak";
    char st[20] = "...";

    printf("Please input your name : ");
    // scanf("%s", &name);
    // scanf("%s", &st);

    gets(name);

    // printf(" -- %s --\n", name);

    printf("name - %s", name);
    printf("\nst - %s", st);

    // puts(name);
    // puts(st);

    puts(".");
}
