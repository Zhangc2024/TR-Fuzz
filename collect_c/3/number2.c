/* c-examples by A.A.Shtanyuk */
/* number2.c - What have you entered? */

#include <stdio.h>

int main()
{
   char mes[]="You entered";
   char numbers[][20]={"a positive number","a negative number","ZERO"};
   int val;

   printf("Enter a number: ");
   scanf("%d",&val);

   if(val>0)
      printf("%s %s!\n",mes,numbers[0]);
   else if(val<0)
      printf("%s %s!\n",mes,numbers[1]);
   else
      printf("%s %s!\n",mes,numbers[2]);
   return 0;
}
