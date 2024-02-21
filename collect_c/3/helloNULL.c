/* c-examples by A.Shtanyuk */
/* helloNULL.c - Hello world with NULL*/

#include <stdio.h>

int main()
{
   char str[]="Hello,\0 world!";
   printf(str);
   printf(str+8);
   return 0;
}
