/* c-examples by A.A.Shtanyuk */
/* name_age.c - Dialog with name and age */

#include <stdio.h>
#include <string.h>
int main()
{
    char name[30];
    int age; 
    printf ("What is your name?\n");
    scanf(name,30,stdin);
    printf ("How old are you?\n");
    scanf ("%d",&age);
    printf ("Your name is '%s'. And you age is '%d'",name,age);
    return 0;
}
