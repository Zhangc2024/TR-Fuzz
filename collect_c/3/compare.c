/* c-examples by A.Shtanyuk */
/* compare.c - compare strings */

#include <stdio.h>

int strcomp(char *d, char *s)
{
   while(*s && *d && *s++==*d++);
   return *s+*d;
}
int main(int argc, char *argv[])
{
   char str[100]="A string";
   printf("%d\n",strcomp(str,"A string"));
   return 0;
}
