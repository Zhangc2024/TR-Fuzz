/* c-examples by A.A.Shtanyuk */
/* print_mes.c - printing and pointers*/

#include <stdio.h>

char *mes[]={"Hello!", 
             "How are you?", 
			 "Get out!"};

int main()
{
   int i;
   char *s;
   for(i=0;i<3;i++)
   {
      s=mes[i];
      while(*s)
         putchar(*s++);
      putchar('\n');
   }
   return 0;
}
