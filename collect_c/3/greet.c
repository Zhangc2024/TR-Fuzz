/* c-examples by A.A.Shtanyuk */
/* greet.c - Hello, there! */

#include <stdio.h>

int main()
{
   char name[256];
   printf("Hello, what is your name? ");
   scanf("%s",name);
   printf("Hello again, %s!",name);
   return 0;
}
