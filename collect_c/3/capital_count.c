/* c-examples by A.Shtanyuk */
/* capital_count.c - Capital letter counter */

#include <stdio.h>

int main()
{
   int count=0,i=0;
   char str[]="123456qwertyKLJ:KJ:LKJ:KL";

   while(str[i])
   {
      if(str[i]>='A' && str[i]<='Z')
         count++;
      i++;
   }

   printf("%d\n",count);
   return 0;
}
