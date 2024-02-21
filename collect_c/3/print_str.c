/* c-examples by A. Shtanyuk */
/* print_str.c - print string, one char per line*/

#include <stdio.h>

int main()
{
   char str[]="qwertyuio";
   int i=0;
   while(str[i++])
   {
      putchar(str[i]);
      putchar('\n');
   }
   return 0;
}
